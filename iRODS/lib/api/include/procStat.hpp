/*** Copyright (c), The Regents of the University of California            ***
 *** For more information please refer to files in the COPYRIGHT directory ***/
/* procStat.h - This dataObj may be generated by a program or script
 */

#ifndef PROC_STAT_HPP
#define PROC_STAT_HPP

/* This is a Object File I/O API call */

#include "rods.hpp"
#include "procApiRequest.hpp"
#include "apiNumber.hpp"
#include "initServer.hpp"

/* fake attri index for procStatOut */
#define PID_INX                 1000001
#define STARTTIME_INX           1000002
#define CLIENT_NAME_INX         1000003
#define CLIENT_ZONE_INX         1000004
#define PROXY_NAME_INX          1000005
#define PROXY_ZONE_INX          1000006
#define REMOTE_ADDR_INX         1000007
#define PROG_NAME_INX           1000008
#define SERVER_ADDR_INX         1000009

typedef struct {
    char addr[LONG_NAME_LEN];       /* if non empty, stat at this addr */
    char rodsZone[NAME_LEN];	    /* the zone */ 
    keyValPair_t condInput;
} procStatInp_t;

#define ProcStatInp_PI "str addr[LONG_NAME_LEN];str rodsZone[NAME_LEN];struct KeyValPair_PI;"

#define MAX_PROC_STAT_CNT	2000

#if defined(RODS_SERVER)
#define RS_PROC_STAT rsProcStat
/* prototype for the server handler */
int
rsProcStat (rsComm_t *rsComm, procStatInp_t *procStatInp, 
genQueryOut_t **procStatOut);
int
_rsProcStat (rsComm_t *rsComm, procStatInp_t *procStatInp,
genQueryOut_t **procStatOut);
int
_rsProcStatAll (rsComm_t *rsComm, procStatInp_t *procStatInp, 
genQueryOut_t **procStatOut);
int
localProcStat (rsComm_t *rsComm, procStatInp_t *procStatInp,
genQueryOut_t **procStatOut);
int
remoteProcStat (rsComm_t *rsComm, procStatInp_t *procStatInp,
genQueryOut_t **procStatOut, rodsServerHost_t *rodsServerHost);
int
initProcStatOut (genQueryOut_t **procStatOut, int numProc);
int
addProcToProcStatOut (procLog_t *procLog, genQueryOut_t *procStatOut);
#else
#define RS_PROC_STAT NULL
#endif

#ifdef  __cplusplus
extern "C" {
#endif

/* prototype for the client call */
/* rcProcStat - Get the connection stat of irods agents running in the 
 * iRods federation. By default, the stat of the irods agents on the icat 
 * enabled server (IES) is listed. Other servers can be specified using
 * the "addr" field of procStatInp or using the RESC_NAME_KW keyword.
 * 
 * Input -
 *   rcComm_t *conn - The client connection handle.
 *   procStatInp_t *procStatInp :
 *      addr - the IP address of the server where the stat should be done.
 * 	    A zero len addr means no input.
 *      rodsZone - the zone name for this stat.  A zero len rodsZone means
 *          the stat is to be done in the local zone.
 *      condInput - conditional Input
 *          RESC_NAME_KW - "value" - do the stat on the server where the 
 *	    Resource is located. 
 *	    ALL_KW (and zero len value) - stat for all servers in the
 *	     fedration.  
 * Output - 
 *   genQueryOut_t **procStatOut
 *	The procStatOut contains 9 attributes and value arrays with the
 *      attriInx defined above. i.e.:
 * 		PID_INX - pid of the agent process
 *		STARTTIME_INX - The connection start time in secs since Epoch.
 *		CLIENT_NAME_INX - client user name
 *		CLIENT_ZONE_INX - client user zone
 *		PROXY_NAME_INX - proxy user name
 *		PROXY_ZONE_INX - proxy user zone
 *		REMOTE_ADDR_INX - the from address of the connection
 *		SERVER_ADDR_INX - the server address of the connection
 * 		PROG_NAME_INX - the client program name
 *
 *	A row will be given for each running irods agent. If a server is 
 *	completely idle, one row will still be given with all the attribute
 *	vaules empty (zero length string) except for the value associated 
 *	with the SERVER_ADDR_INX. 
 *   return value - The status of the operation.
 */

int
rcProcStat (rcComm_t *conn, procStatInp_t *procStatInp,
genQueryOut_t **procStatOut);
#ifdef  __cplusplus
}
#endif

#endif	/* PROC_STAT_H */
