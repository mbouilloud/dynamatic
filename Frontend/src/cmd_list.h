/*
*  C++ Implementation: dhls
*
* Description:
*
*
* Author: Andrea Guerrieri <andrea.guerrieri@epfl.ch (C) 2019
*
* Copyright: See COPYING file that comes with this distribution
*
*/


#include <string>
#include <vector>

using namespace std;


typedef struct ui_cmd_t
{
	char *cmd;
	char *help;
	int (*function) ( string input_cmp );
} UI_CMD_T;

#define UI_CMD_HELP	"help"

enum
{
  CMD_HELP1,
  CMD_HELP2,
  CMD_SOURCE,
  CMD_CLEAN_MILP, // Mathias 22.06.2023 add milp files cleaning command
  CMD_PROJ,
  CMD_ADD_FILE,
  CMD_SET_PERIOD,
  CMD_SET_SLOTS, // Mathias 16.06.2023 add resource constrained optimization to buffer algo
  CMD_SET_TARGET,
  CMD_SET_MILP_MODE,   //Carmine 23.02.22 adding the functionality of milp mode to dynamatic basic code
  CMD_SET_MILP_SOLVER,   //Carmine 25.02.22 setting MILP solver
  CMD_ANALYZE,
  CMD_ELABORATE,
  CMD_SYNTHESIZE,
  CMD_OPTIMIZE,
  CMD_PHASE_OPTIMIZE, // Mathias 22.06.2023 add phase optimization to Dynamatic
  CMD_WRITE_HDL,
//  CMD_REPORTS,
  CMD_CDFG,
//  CMD_STATUS,
//  CMD_SIMULATE,
  CMD_UPDATE,
  CMD_HISTORY,
  CMD_ABOUT,
  CMD_EXIT,
  CMD_MAX
};

static UI_CMD_T ui_cmds[] =
{
	{"help","         : Shows Available commands"		},
	{"?","            : Shows Available commands"		},
	{"source","       : Source a script file"},
	{"clean_milp","       : Clean optimization files"},
	{"set_project","  : Set the project directory"},
	{"set_top_file"," : Set the top level file"},
	{"set_period","   : Set the hardware period"},
	{"set_slots","   : Set max number of buffer slots"},
	{"set_target","   : Set target FPGA"},
  {"set_milp_mode","   : Set MILP working mode"},     //Carmine 23.02.22 adding the functionality of milp mode to dynamatic basic code
  {"set_milp_solver","   : Set MILP solver"},     //Carmine 25.02.22 setting MILP solver
    {"analyze","      : Analyze source"				},
	{"elaborate","    : Elaborate source"				},
	{"synthesize","   : C synthesis"				},
	{"optimize","     : Timing optmizations"				},
	{"phase_optimize","     : Phase optmizations"				}, // Mathias 22.06.2023 add phase optimization to buffer algo
	{"write_hdl","    : Generate VHDL"				},
//	{"reports","      : Report resources and timing "},
	{"cdfg","         : Show control data flow graph "},
//	{"status","       : Report design status "},
//	{"simulate","     : Simulation "},
	{"update","       : Check for updates "},
	{"history","      : History command list "},
 	{"about","        : Disclaimers & Copyrights"		},
    {"exit","         : Exit"				},
 	{NULL,		NULL,	0}
};



