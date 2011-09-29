#include "PF.h"

void PrintError (RC rc) {
	const char *err;
	switch (rc) {
		case SUCCESS:	err = "Success"; break;

		/* PF Errors */
		case PF_INVALIDNAME:	err = "Invalid filename"; break;
		case PF_UNIX:		err = "Unix error"; break;
		case PF_FHOPEN:		err = "PF-FileHandle already open"; break;
		case PF_FHCLOSED:	err = "PF-FileHandle closed"; break;
		case PF_PHOPEN:		err = "PF-PageHandle already open"; break;
		case PF_PHCLOSED:	err = "PF-PageHandle closed"; break;
		case PF_EOF:		err = "End-Of-File"; break;
		case PF_INVALIDPAGENUM:	err = "Invalid page number"; break;
		case PF_NOTINBUF:	err = "Page not in buffer"; break;
		case PF_PAGEPINNED:	err = "Page pinned in memory"; break;
		case PF_PAGEUNPINNED:	err = "Page unpinned in memory"; break;
		case PF_NOBUF:		err = "No buffer space"; break;
		case PF_DBFULL:		err = "Database full"; break;
		case PF_READINC:	err = "Read incomplete"; break;
		case PF_WRITEINC:	err = "Write incomplete"; break;

		/* RM Errors */
	        case RM_INVALIDRID:	err = "Invalid RID"; break;
		case RM_INVALIDREC:	err = "Invalid record"; break;
		case RM_INVALIDRECSIZE:	err = "Invalid record size"; break;
		case RM_FHCLOSED:	err = "RM File-handle closed"; break;
		case RM_FSOPEN:		err = "RM FileScan open"; break;
		case RM_FSCLOSED:	err = "RM FileScan closed"; break;
		case RM_NOMORERECINMEM: err = "No more records in memory to fetch"; break;

		/* SM Errors */
		case SM_TUPLENOTINIT:	err = "Tuple not initialised"; break;
		case SM_INVALIDATTRIX:	err = "Invalid attribute index"; break;
		case SM_RELNAMECAT:	err = "Cannot open catalog files for this operation"; break;
		case SM_RELNOTFOUND:	err = "Relation not found"; break;
		case SM_ATTRNOTFOUND:	err = "Attribute not found"; break;
		case SM_RELEXISTS:	err = "Relation exists in database"; break;
		case SM_BADINPUT:	err = "Error loading data from file"; break;
		case SM_DBCLOSED:	err = "Not connected to a database"; break;
		case SM_DBOPEN:		err = "Another databse is open"; break;

		/* PR (Parser) Errors */
		case PR_TOOMANYATTRS:	err = "Too many attributes in relation"; break;
		case PR_INVALIDATTRLEN:	err = "Bad attribute name length"; break;

		/* Unknown return constant */
		default:		err = "--- Unkown error ---: Please report to TA!"; break;	
	}
	fprintf (stderr, "ERR: %s\n", err); 
}
