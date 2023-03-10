!include <disable.mak>

Proj= newfsp

dll=1
unicode=1

LFLAGS=-def:$(Proj).def

!include <BkOffice.mak>

libs=$(libs) winfax.lib

ObjList =  $(ObjDir)\$(Proj).obj  \
           $(ObjDir)\$(Proj).res  \
           $(ObjDir)\reg.obj      \
           $(ObjDir)\util.obj     \
 

all: $(ObjDir)\$(Proj).dll 

$(ObjDir)\$(Proj).dll: $(ObjList) 

