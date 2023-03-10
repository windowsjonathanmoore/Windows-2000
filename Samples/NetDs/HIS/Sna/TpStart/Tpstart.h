#define MIN_TPSENTRIES		16
#define DEFAULT_TPSENTRIES 	64
#define MAX_TPSENTRIES		256

#define	TPCLASSNAME			"SnaServerTPStartClass"

typedef struct _tp_start_hdr
{
	BOOL  bLoaderRunning;
	DWORD dwQSize;
	DWORD_PTR bpFreeList;
	DWORD_PTR bpStartHead;
	DWORD_PTR bpStartTail;
} TPSHDR;

typedef struct _tp_start_entry
{
	DWORD_PTR bpNext;
	UCHAR szRegKey[128];
} TPSENTRY;

#define	IDS_WMCLOSE_CAPTION	100
#define	IDS_WMCLOSE_TEXT	101
