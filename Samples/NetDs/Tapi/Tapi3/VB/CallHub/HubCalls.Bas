Attribute VB_Name = "HubCalls"

'
'--------------------------------------------------------------------------
'
'  Copyright (C) 1997-1999 Microsoft Corporation. All rights reserved.
'
'--------------------------------------------------------------------------
'
'Functions for "Hub" Calls
'
'CHTree = Call Hubs Tree
'
'Notes:
' - Bug in VB5: can't store objects in Nodes.Tag, so store them in
' a separatecollection. (this is fixed in VB6).
'

Option Explicit

Private Const gszCallHub = "ITCallHub"

Public Function CHTree_Unload(tree As TreeView, treeCollData As Collection) As Long
    
    Dim objNode As Node
    Dim nIndex
    
    'assert
    If tree.Nodes.Count <> treeCollData.Count Then
        MsgBox ("ASSERT: CallHubs: TreeNodes and TreeDataCollection have different number of elements!")
    End If
    
    'release tree data
    For Each objNode In tree.Nodes
        'Set objNode.Tag = Nothing      'doesn't work
        treeCollData.Remove (1)
    Next
    
    'release all nodes
    tree.Nodes.Clear
    
End Function

Public Function CHTree_Load( _
    tree As TreeView, _
    treeCollData As Collection, _
    varCallHubs) As Long
    
    Dim nIndex
    Dim collCallHubs As ITCollection
    Dim objCrtCallHub  As ITCallHub
    Dim objCrtNode  As Node
    
    Set collCallHubs = varCallHubs
    
    For nIndex = 1 To collCallHubs.Count
        Set objCrtCallHub = collCallHubs.Item(nIndex)
        
        '
        'create new node for this call hub
        '
        Set objCrtNode = tree.Nodes.Add(Text:=gszCallHub)
        objCrtNode.EnsureVisible
        
        '
        'save a reference of CallHub right in the node
        '
        'Set objCrtNode.Tag = objCrtCallHub     'doesn't work
        If objCrtNode.Index = 1 Then
            Call treeCollData.Add(Item:=objCrtCallHub)  'it is the 1st node
        Else
            Call treeCollData.Add(Item:=objCrtCallHub, after:=objCrtNode.Index - 1)
        End If
        
        'assert: check that the node and its data have the same index
        If Not (objCrtCallHub Is treeCollData(objCrtNode.Index)) Then
            MsgBox ("ASSERT: " & "CallHubs: " & _
            "Tree's Node-Collection and Data-Collection do not have the same index! ")
        End If
        
        '
        'create "participants" nodes
        '
        Call LoadParticipantCalls(tree, treeCollData, objCrtNode.Index, objCrtCallHub)
        
        Set objCrtNode = Nothing
        Set objCrtCallHub = Nothing
    Next nIndex
    
    Set collCallHubs = Nothing
    
End Function

Public Function CHTree_DisplayNode( _
    ByVal objNode As ComctlLib.Node, _
    treeCollData As Collection) As Long
    
    '
    'find the data corresponding to this node
    '
    
    Dim objData As Object
    
    'Set objData = objNode.Tag              'doesn't work
    Set objData = treeCollData.Item(objNode.Index)
    
    If objData Is Nothing Then
        
        frmCallHubs.txtDescriptionCH.Text = "Not Available"
        frmCallHubs.txtDescriptionCH.Refresh
        
        Set objData = Nothing
        
        CHTree_DisplayNode = 0
        Exit Function
    End If
    
    '
    'detect what kind of object is stored in node
    'by using its title
    '
    
    Select Case objNode.Text
        Case gszCallHub
            Dim objCallHub As ITCallHub
            Set objCallHub = objData
            Call DisplayCallHub(objCallHub)
            Set objCallHub = Nothing
    
        Case gszParticipantCall
            Dim objCallInfo As ITCallInfo
            Set objCallInfo = objData
            Call DisplayCallInfo(objCallInfo, frmCallHubs.txtDescriptionCH)
            Set objCallInfo = Nothing
    
        Case gszCallControl
            Dim objCallControl As ITBasicCallControl
            Set objCallControl = objData
            Call DisplayCallControl(objCallControl, frmCallHubs.txtDescriptionCH)
            Set objCallControl = Nothing
    
        Case gszLegacyCallMediaControl
            Dim objLegacyCallMediaControl As ITLegacyCallMediaControl
            Set objLegacyCallMediaControl = objData
            Call DisplayLegacyCallMediaControl(objLegacyCallMediaControl, frmCallHubs.txtDescriptionCH)
            Set objLegacyCallMediaControl = Nothing
    
        Case gszStreamControl
            Dim objStreamControl As ITStreamControl
            Set objStreamControl = objData
            Call DisplayStreamControl(objStreamControl, frmCallHubs.txtDescriptionCH)
            Set objStreamControl = Nothing
    
        Case Else
            'assert
            MsgBox ("ASSERT: unkown type of node in <call hubs> tree")
            
    End Select
    
    Set objData = Nothing
End Function

'
Public Function CHTree_AddNewCallHub( _
    tree As TreeView, _
    treeCollData As Collection, _
    objCallHub As ITCallHub) As Long

    Dim objNewNode As Node
    
    '
    'create new node for this call hub (add it the last, at root level)
    '
    Set objNewNode = tree.Nodes.Add(Text:=gszCallHub)
    objNewNode.EnsureVisible
    
    '
    'save a reference of CallHub right in the node
    '
    'Set objNewNode.Tag = objCallHub        'doesn't work
    If objNewNode.Index = 1 Then
        Call treeCollData.Add(Item:=objCallHub)     'it is the 1st node
    Else
        Call treeCollData.Add(Item:=objCallHub, after:=objNewNode.Index - 1)
    End If
    
    'assert: check that the node and its data have the same index
    If Not (objCallHub Is treeCollData(objNewNode.Index)) Then
        MsgBox ("ASSERT: " & "CallHubs: " & _
        "Tree's Node-Collection and Data-Collection do not have the same index! ")
    End If
    
    Set objNewNode = Nothing
    
    '
    'for the participant calls already existing in the callhub received
    'on CHE_CALLHUBNEW, there might be no event CHE_CALLJOIN,
    'so I have to add them right here:
    '
    Dim collParticipantCalls As ITCollection
    Set collParticipantCalls = objCallHub.Calls
    
    If objCallHub.NumCalls <> collParticipantCalls.Count Then
        MsgBox ("ERROR: " & "CallHubs: " & _
        "objCallHub.NumCalls <> collParticipantCalls.Count ! ")
    End If
    
    Dim nIndex As Long
    Dim objCrtParticipantCall As ITCallInfo
    
    For nIndex = 1 To collParticipantCalls.Count
        Set objCrtParticipantCall = collParticipantCalls.Item(nIndex)
        Call CHTree_AddNewParticipantCall(tree, treeCollData, _
            objCrtParticipantCall, objCallHub)
        Set objCrtParticipantCall = Nothing
    Next
        
    Set collParticipantCalls = Nothing
        
End Function

Public Function CHTree_RemoveCallHub( _
    tree As TreeView, _
    treeCollData As Collection, _
    objCallHub As ITCallHub) As Long
    
    Dim nNodeIndex As Variant
    nNodeIndex = Empty
    
    '
    'search in tree the node that contains this CallHub and remember its index
    '
    Dim objCrtCallHub As ITCallHub
    Dim nIndex As Long
    
    For nIndex = 1 To tree.Nodes.Count
        If tree.Nodes.Item(nIndex).Text = gszCallHub Then
            'Set objCrtCallHub = tree.Nodes.Item(nIndex).Tag    'doesn't work
            Set objCrtCallHub = treeCollData.Item(nIndex)
            
            If objCrtCallHub Is objCallHub Then
                nNodeIndex = tree.Nodes.Item(nIndex).Index
                
                Set objCrtCallHub = Nothing
                Exit For
            End If
            
            Set objCrtCallHub = Nothing
        End If
    Next nIndex
    
    If IsEmpty(nNodeIndex) Then
        MsgBox ("ERROR: can't find node that contains this CallHub")
        CHTree_RemoveCallHub = 1   '1 = error code
        Exit Function
    End If
        
'
'The following assumption is not true! Most of the TSPs don't fire the CHE_CALLLEAVE
'event. So for most of them TAPI3 will send CHE_CALLHUBIDLE without sendind first
'CHE_CALLLEAVE, which means that CHE_CALLHUBIDLE will be received when
'call still has "participant call" children in the tree.
'
'    '
'    'A call hub becomes idle when all participant calls are gone =>
'    '=> idle callhub should have 0 children !!!
'    '
'    If tree.Nodes.Item(nNodeIndex).Children <> 0 Then
'        MsgBox ("ERROR: idle CallHub still has children!")
'    End If
'

    '
    'remove node
    '
    Call RemoveNode(tree, treeCollData, nNodeIndex)
    
End Function
                    
'
Public Function CHTree_AddNewParticipantCall( _
    tree As TreeView, _
    treeCollData As Collection, _
    objParticipantCall As ITCallInfo, _
    objCallHub As ITCallHub) As Long
    
    Dim nParentNodeIndex As Variant
    nParentNodeIndex = Empty
    
    '
    'check that the participant call mentions the same parent CallHub
    'as the event CHE_CALLJOIN mentioned
    '
    
    If Not (objCallHub Is objParticipantCall.CallHub) Then
        MsgBox ("ERROR: the <calljoin event> and the <joining participant call> " & _
            "indicate different callhub parent! " & _
            "Try reloading all callhubs...")
        CHTree_AddNewParticipantCall = 1   '1 = error code
        Exit Function
    End If
    
    '
    'if participant is already in tree, and under the same callhub parent
    'as CHE_CALLJOIN sais, don't add it
    '
    If IsParticipantCallInRightPlaceInTree( _
        tree, treeCollData, objParticipantCall, objCallHub) Then
        Call PrintWarning( _
            "CHTree_AddNewParticipantCall: new participant CallInfo is already in tree, " & _
            "under the correct callhub parent " & _
            "(maybe added by CHTree_AddNewCallHub)!")
        
        CHTree_AddNewParticipantCall = 2   '2 = warning code
        Exit Function
    End If
    
    
    '
    'search in tree the CallHub that owns the participant call,
    'and remember its "node" index
    '
    Dim objCrtCallHub As ITCallHub
    Dim objParentCallHub As ITCallHub
    Dim nIndex As Long
    
    For nIndex = 1 To tree.Nodes.Count
        If tree.Nodes.Item(nIndex).Text = gszCallHub Then
            
            'Set objCrtCallHub = tree.Nodes.Item(nIndex).Tag    'doesn't work
            Set objCrtCallHub = treeCollData.Item(nIndex)
            
            On Error Resume Next
            Set objParentCallHub = objParticipantCall.CallHub
            If Err.Number <> 0 Then
                Dim strMsg
                strMsg = _
                    "CHTree_AddNewParticipantCall: objParticipantCall.CallHub failed " & _
                    "with err.number = 0x" & Hex(Err.Number)
                MsgBox (strMsg)
                'Err.Clear
                On Error GoTo 0
            End If
            On Error GoTo 0
            
            If objCrtCallHub Is objParentCallHub Then
                nParentNodeIndex = tree.Nodes.Item(nIndex).Index

                Set objCrtCallHub = Nothing
                Set objParentCallHub = Nothing
                Exit For
            End If
            
            Set objCrtCallHub = Nothing
            Set objParentCallHub = Nothing
        End If
    Next nIndex
    
    If IsEmpty(nParentNodeIndex) Then
        MsgBox ("ERROR: can't find parent CallHub of new participant call in <CallHubs> tree")
        CHTree_AddNewParticipantCall = 1   '1 = error code
        Exit Function
    End If
    
    '
    'add the participant as a "child node" of the found CallHub; use the found "index"
    '
    Call LoadParticipantCall(tree, treeCollData, nParentNodeIndex, objParticipantCall)
    
    CHTree_AddNewParticipantCall = 0
    Exit Function
End Function

Public Function CHTree_RemoveParticipantCall( _
    tree As TreeView, _
    treeCollData As Collection, _
    objParticipantCall As ITCallInfo) As Long
    
    Dim nNodeIndex As Variant
    nNodeIndex = Empty
    
    '
    'search in tree the node that contains this participant call and remember its index
    '
    Dim objCrtParticipantCall As ITCallInfo
    Dim nIndex As Long
    
    For nIndex = 1 To tree.Nodes.Count
        If tree.Nodes.Item(nIndex).Text = gszParticipantCall Then
            'Set objCrtParticipantCall= tree.Nodes.Item(nIndex).Tag   'doesn't work
            Set objCrtParticipantCall = treeCollData.Item(nIndex)
            
            If objCrtParticipantCall Is objParticipantCall Then
                nNodeIndex = tree.Nodes.Item(nIndex).Index
                
                Set objCrtParticipantCall = Nothing
                Exit For
            End If
            
            Set objCrtParticipantCall = Nothing
        End If
    Next nIndex
    
    If IsEmpty(nNodeIndex) Then
        MsgBox ("ERROR: can't find node that contains this participant")
        CHTree_RemoveParticipantCall = 1   '1 = error code
        Exit Function
    End If
        
    '
    'remove node
    '
    
    Call RemoveNode(tree, treeCollData, nNodeIndex)
    
End Function

Public Function CHTree_IsCallHubSelected( _
    tree As TreeView, _
    treeCollData As Collection, _
    objCallHub As ITCallHub) As Boolean
    
    CHTree_IsCallHubSelected = False
    
    Dim objSelNode As Node
    
    Set objSelNode = tree.SelectedItem
    
    If Not (objSelNode Is Nothing) Then
        If objCallHub Is treeCollData.Item(objSelNode.Index) Then
            CHTree_IsCallHubSelected = True
        End If
    End If
        
    Set objSelNode = Nothing
    
End Function

Public Function CHTree_IsParticipantCallSelected( _
    tree As TreeView, _
    treeCollData As Collection, _
    objParticipantCall As ITCallInfo) As Boolean
    
    CHTree_IsParticipantCallSelected = False
    
    Dim objSelNode As Node
    
    Set objSelNode = tree.SelectedItem
    
    If Not (objSelNode Is Nothing) Then
        If objParticipantCall Is treeCollData.Item(objSelNode.Index) Then
            CHTree_IsParticipantCallSelected = True
        End If
    End If
        
    Set objSelNode = Nothing
    
End Function

Public Function CHTree_DisplaySelectedNode( _
    tree As TreeView, treeCollData As Collection) As Long

    Dim objSelNode As Node
    
    Set objSelNode = tree.SelectedItem
    
    're-display information about node (refresh)
    If Not (objSelNode Is Nothing) Then
        Call CHTree_DisplayNode(objSelNode, treeCollData)
    End If
    
    Set objSelNode = Nothing

End Function

'
Private Function LoadParticipantCalls( _
    tree As TreeView, _
    treeCollData As Collection, _
    nParentNodeIndex, _
    objCallHub As ITCallHub) As Long

    Dim nIndex
    Dim collParticipantCalls As ITCollection
    Dim objCrtParticipantCall As ITCallInfo
    
    Set collParticipantCalls = objCallHub.Calls
    
    For nIndex = 1 To collParticipantCalls.Count
        
        Set objCrtParticipantCall = collParticipantCalls.Item(nIndex)
        
        '
        'check that objCrtParticipantCall.CallHub is the same as objCallHub
        '
        If Not (objCallHub Is objCrtParticipantCall.CallHub) Then
            MsgBox ("LoadParticipantCalls: invalid objCrtParticipantCall.CallHub")
        End If
        
        '
        'create new node for this participant call
        '
        Call LoadParticipantCall(tree, treeCollData, nParentNodeIndex, objCrtParticipantCall)
        
        Set objCrtParticipantCall = Nothing
    Next nIndex
    
    Set collParticipantCalls = Nothing
    
End Function

'
Private Function LoadParticipantCall( _
    tree As TreeView, _
    treeCollData As Collection, _
    nParentNodeIndex, _
    objParticipantCall As ITCallInfo) As Long

    Dim objNewNode As Node
    
    'create new node

    Set objNewNode = tree.Nodes.Add( _
        Relative:=nParentNodeIndex, _
        Relationship:=tvwChild, _
        Text:=gszParticipantCall)
    objNewNode.EnsureVisible
        
    'save a reference of Participant Call right in the node
    'Set objNewNode.Tag = objParticipantCall     'doesn't work
    If objNewNode.Index = 1 Then
        Call treeCollData.Add(Item:=objParticipantCall)        'it is the 1st node
    Else
        Call treeCollData.Add(Item:=objParticipantCall, after:=objNewNode.Index - 1)
    End If
        
    'assert
    If Not (objParticipantCall Is treeCollData.Item(objNewNode.Index)) Then
        MsgBox ("ASSERT: CallHubs: LoadParticipantCall: node and data have different index")
    End If
        
    'create nodes for all call interfaces that can be queried
    'from this participant
    Call LoadCallInterfaces(tree, treeCollData, objNewNode.Index, objParticipantCall)
        
    Set objNewNode = Nothing
End Function

'
Private Function DisplayCallHub(objCallHub As ITCallHub) As Long
    
    Dim strText As String
    
    strText = _
        "State = " & objCallHub.State & _
            Chr(13) & Chr(10) & _
        "Num Participant Calls = " & objCallHub.NumCalls
    
    frmCallHubs.txtDescriptionCH.Text = strText
    frmCallHubs.txtDescriptionCH.Refresh
    
End Function
   
'
'The following function returns TRUE if it finds the call in the tree
'and if also the parent node contains the indicated callhub.
'
'Otherwise, it returns FALSE, because it means that the call is not in the
'tree, or it is in the tree, but under the wrong callhub parent.
'
'The latter will happen for example in a conference scenario, where a call exists
'under one callhub for a while, then once the conference is fully setup,
'(Finish is called) the same call moves under another callhub. Depending
'on the order in the events CHE_CALLLEAVE and CHE_CALLJOIN are fired,
'you might see a CHE_CALLJOIN firing to say that "this call joined this callhub"
'for a call which is already in the tree, but under the old callhub.
'
Private Function IsParticipantCallInRightPlaceInTree( _
    tree As TreeView, _
    treeCollData As Collection, _
    objCallInfo As ITCallInfo, _
    objCallHub As ITCallHub) As Boolean
    
    Dim nNodeIndex As Variant
    nNodeIndex = Empty
    
    '
    'search in tree the node that contains this call;
    'if its parent is the expected callhub, remember this call's index
    '
    Dim objCrtCallInfo As ITCallInfo
    Dim objParentCallHub As ITCallHub
    Dim nIndex As Long, nIndexOfParent As Long
    
    For nIndex = 1 To tree.Nodes.Count
        If tree.Nodes.Item(nIndex).Text = gszCallInfo Then
            'Set objCrtCallInfo = tree.Nodes.Item(nIndex).Tag   'doesn't work
            Set objCrtCallInfo = treeCollData.Item(nIndex)
            
            If objCrtCallInfo Is objCallInfo Then
            
                'Find out the parent node of this node,
                'and extract the callhub object from the parent.
                'Note:
                'it is a "participant call" node, so it always has a non null parent.
                
                nIndexOfParent = tree.Nodes.Item(nIndex).Parent.Index
                Set objParentCallHub = treeCollData.Item(nIndexOfParent)
                
                'if parent callhub is the expected one, we're done
                
                If objCallHub Is objParentCallHub Then
                    
                    'we found the node in the tree, under
                    'the expected callhub parent; let's remember its index.
                    
                    nNodeIndex = tree.Nodes.Item(nIndex).Index
                    
                    Set objParentCallHub = Nothing
                    Set objCrtCallInfo = Nothing
                    Exit For
                End If
                
                Set objParentCallHub = Nothing
            End If
            
            Set objCrtCallInfo = Nothing
        End If
    Next nIndex
    
    If IsEmpty(nNodeIndex) Then
        'didn't find node that contains this call
        'or found it under another callhub parent.
        IsParticipantCallInRightPlaceInTree = False
        Exit Function
    End If
    
    IsParticipantCallInRightPlaceInTree = True
    Exit Function
End Function
