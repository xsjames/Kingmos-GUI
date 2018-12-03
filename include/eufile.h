/******************************************************
Copyright(c) ��Ȩ���У�1998-2003΢�߼�����������Ȩ����
******************************************************/

#ifndef __EUFILE_H
#define __EUFILE_H

#ifdef __cplusplus
extern "C" {
#endif      //__cplusplus

enum{
	FILE_CREATEDIRECTORY = 1,
	FILE_CREATEFILE,
	FILE_CLOSEFILE,
	FILE_DELETEANDRENAME,
	FILE_DELETE,
	FILE_DEVICEIOCONTROL,
	FILE_FINDCLOSE,
	FILE_FINDFIRST,
	FILE_FINDNEXT,
	FILE_FLUSHBUFFERS,
	FILE_GETDISKFREESPACEEX,
	FILE_GETATTRIBUTES,
	FILE_GETINFORMATION,
	FILE_GETSIZE,
	FILE_GETTIME,
	FILE_MOVE,
	FILE_READ,
	FILE_READWITHSEEK,
	FILE_REMOVEDIRECTORY,
	FILE_SETEND,
	FILE_SETATTRIBUTES,
	FILE_SETPOINTER,
	FILE_SETTIME,
	FILE_WRITE,
	FILE_WRITEWITHSEEK,
	FILE_COPY
};

enum{
	//FSMGR_LOADFSD = 1,
	FSMGR_GETDISKINFO = 1,
	FSMGR_READDISK,
	FSMGR_WRITEDISK,
	FSMGR_REGISTERVOLUME,
	FSMGR_REGISTERFSD,
	FSMGR_UNREGISTERFSD,
	FSMGR_GETVOLUMENAME,
	FSMGR_DEREGISTERVOLUME,
	FSMGR_CREATEFILEHANDLE,
	FSMGR_CLOSEFILEHANDLE,
	FSMGR_CREATESEARCHHANDLE,
	FSMGR_CLOSESEARCHHANDLE,
	FSMGR_DEVICEIOCONTROL
};

enum{
    REG_CLOSEKEY = 1,
    REG_CREATEKEYEX,
    REG_DELETEKEY,
    REG_DELETEVALUE,
    REG_ENUMKEYEX,
    REG_FLUSHKEY,
    REG_ENUMVALUE,
    REG_OPENKEYEX,
    REG_QUERYINFOKEY,
    REG_QUERYVALUEEX,
    REG_SETVALUEEX
};


#ifdef __cplusplus
}
#endif  //__cplusplus


#endif // __EUFILE_H