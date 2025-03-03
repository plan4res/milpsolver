/* FILE GENERATED AUTOMATICALLY, DO NOT EDIT */

#include <gurobi_c.h>
#include "GRBMILPSolver.h"

using namespace SMSpp_di_unipi_it;

const std::array< std::string, GRB_NUM_INT_PARS > GRBMILPSolver::SMSpp_to_GUROBI_int_pars{
 "SolutionLimit",
 "Method",
 "ScaleFlag",
 "SimplexPricing",
 "Quad",
 "NormAdjust",
 "SiftMethod",
 "Sifting",
 "LPWarmStart",
 "NetworkAlg",
 "BarIterLimit",
 "BarCorrectors",
 "BarHomogeneous",
 "BarOrder",
 "Crossover",
 "CrossoverBasis",
 "BranchDir",
 "DegenMoves",
 "Disconnected",
 "IntegralityFocus",
 "MinRelNodes",
 "MIPFocus",
 "NodeMethod",
 "OBBT",
 "PumpPasses",
 "RINS",
 "NLPHeur",
 "SolutionNumber",
 "StartNodeLimit",
 "SubMIPNodes",
 "Symmetry",
 "VarBranch",
 "ZeroObjNodes",
 "Cuts",
 "CutPasses",
 "CliqueCuts",
 "CoverCuts",
 "CutAggPasses",
 "FlowCoverCuts",
 "FlowPathCuts",
 "GomoryPasses",
 "GUBCoverCuts",
 "ImpliedCuts",
 "ProjImpliedCuts",
 "MIPSepCuts",
 "MIRCuts",
 "StrongCGCuts",
 "NetworkCuts",
 "SubMIPCuts",
 "ZeroHalfCuts",
 "ModKCuts",
 "InfProofCuts",
 "RLTCuts",
 "RelaxLiftCuts",
 "BQPCuts",
 "PSDCuts",
 "LiftProjectCuts",
 "ServerTimeout",
 "CSPriority",
 "CSIdleTimeout",
 "CSTLSInsecure",
 "TSPort",
 "CSBatchMode",
 "CSClientLog",
 "WLSTokenDuration",
 "LicenseID",
 "Aggregate",
 "AggFill",
 "PreDual",
 "ConcurrentMIP",
 "ConcurrentJobs",
 "DisplayInterval",
 "DistributedMIPJobs",
 "DualReductions",
 "IISMethod",
 "InfUnbdInfo",
 "JSONSolDetail",
 "LogToConsole",
 "MIQCPMethod",
 "NonConvex",
 "NumericFocus",
 "QCPDual",
 "PreCrush",
 "PreDepRow",
 "PreQLinearize",
 "PrePasses",
 "Presolve",
 "PreSOS1Encoding",
 "PreSOS2Encoding",
 "PreSparsify",
 "PreMIQCPForm",
 "Seed",
 "SolutionTarget",
 "Threads",
 "LazyConstraints",
 "TuneResults",
 "TuneCriterion",
 "TuneTrials",
 "TuneOutput",
 "TuneJobs",
 "TuneMetric",
 "UpdateMode",
 "ObjNumber",
 "MultiObjMethod",
 "MultiObjPre",
 "ScenarioNumber",
 "Record",
 "PoolSolutions",
 "PoolSearchMode",
 "IgnoreNames",
 "StartNumber",
 "PartitionPlace",
 "FuncPieces",
 "OutputFlag",
};

const std::array< std::string, GRB_NUM_DBL_PARS > GRBMILPSolver::SMSpp_to_GUROBI_dbl_pars{
 "Cutoff",
 "IterationLimit",
 "NodeLimit",
 "TimeLimit",
 "WorkLimit",
 "MemLimit",
 "SoftMemLimit",
 "BestObjStop",
 "BestBdStop",
 "FeasibilityTol",
 "IntFeasTol",
 "MarkowitzTol",
 "MIPGap",
 "MIPGapAbs",
 "OptimalityTol",
 "PSDTol",
 "PerturbValue",
 "ObjScale",
 "BarConvTol",
 "BarQCPConvTol",
 "Heuristics",
 "NodefileStart",
 "NoRelHeurTime",
 "NoRelHeurWork",
 "CSQueueTimeout",
 "WLSTokenRefresh",
 "PreSOS1BigM",
 "PreSOS2BigM",
 "FeasRelaxBigM",
 "ImproveStartTime",
 "ImproveStartGap",
 "ImproveStartNodes",
 "TuneTimeLimit",
 "TuneCleanup",
 "TuneTargetMIPGap",
 "TuneTargetTime",
 "PoolGap",
 "PoolGapAbs",
 "FuncPieceLength",
 "FuncPieceError",
 "FuncPieceRatio",
 "FuncMaxVal",
};

const std::array< std::string, GRB_NUM_STR_PARS > GRBMILPSolver::SMSpp_to_GUROBI_str_pars{
 "NodefileDir",
 "SolFiles",
 "WorkerPool",
 "WorkerPassword",
 "ComputeServer",
 "JobID",
 "CSRouter",
 "CSGroup",
 "ServerPassword",
 "TokenServer",
 "CloudAccessID",
 "CloudSecretKey",
 "CloudPool",
 "CloudHost",
 "CSManager",
 "CSAuthToken",
 "CSAPIAccessID",
 "CSAPISecret",
 "Username",
 "CSAppName",
 "WLSAccessID",
 "WLSSecret",
 "WLSToken",
 "LogFile",
 "ResultFile",
 "Dummy",
};

const std::array< std::pair< std::string, int >, GRB_NUM_INT_PARS >
 GRBMILPSolver::GUROBI_to_SMSpp_int_pars{
 {
  { "SolutionLimit", intFirstGUROBIPar + 0 },
  { "Method", intFirstGUROBIPar + 1 },
  { "ScaleFlag", intFirstGUROBIPar + 2 },
  { "SimplexPricing", intFirstGUROBIPar + 3 },
  { "Quad", intFirstGUROBIPar + 4 },
  { "NormAdjust", intFirstGUROBIPar + 5 },
  { "SiftMethod", intFirstGUROBIPar + 6 },
  { "Sifting", intFirstGUROBIPar + 7 },
  { "LPWarmStart", intFirstGUROBIPar + 8 },
  { "NetworkAlg", intFirstGUROBIPar + 9 },
  { "BarIterLimit", intFirstGUROBIPar + 10 },
  { "BarCorrectors", intFirstGUROBIPar + 11 },
  { "BarHomogeneous", intFirstGUROBIPar + 12 },
  { "BarOrder", intFirstGUROBIPar + 13 },
  { "Crossover", intFirstGUROBIPar + 14 },
  { "CrossoverBasis", intFirstGUROBIPar + 15 },
  { "BranchDir", intFirstGUROBIPar + 16 },
  { "DegenMoves", intFirstGUROBIPar + 17 },
  { "Disconnected", intFirstGUROBIPar + 18 },
  { "IntegralityFocus", intFirstGUROBIPar + 19 },
  { "MinRelNodes", intFirstGUROBIPar + 20 },
  { "MIPFocus", intFirstGUROBIPar + 21 },
  { "NodeMethod", intFirstGUROBIPar + 22 },
  { "OBBT", intFirstGUROBIPar + 23 },
  { "PumpPasses", intFirstGUROBIPar + 24 },
  { "RINS", intFirstGUROBIPar + 25 },
  { "NLPHeur", intFirstGUROBIPar + 26 },
  { "SolutionNumber", intFirstGUROBIPar + 27 },
  { "StartNodeLimit", intFirstGUROBIPar + 28 },
  { "SubMIPNodes", intFirstGUROBIPar + 29 },
  { "Symmetry", intFirstGUROBIPar + 30 },
  { "VarBranch", intFirstGUROBIPar + 31 },
  { "ZeroObjNodes", intFirstGUROBIPar + 32 },
  { "Cuts", intFirstGUROBIPar + 33 },
  { "CutPasses", intFirstGUROBIPar + 34 },
  { "CliqueCuts", intFirstGUROBIPar + 35 },
  { "CoverCuts", intFirstGUROBIPar + 36 },
  { "CutAggPasses", intFirstGUROBIPar + 37 },
  { "FlowCoverCuts", intFirstGUROBIPar + 38 },
  { "FlowPathCuts", intFirstGUROBIPar + 39 },
  { "GomoryPasses", intFirstGUROBIPar + 40 },
  { "GUBCoverCuts", intFirstGUROBIPar + 41 },
  { "ImpliedCuts", intFirstGUROBIPar + 42 },
  { "ProjImpliedCuts", intFirstGUROBIPar + 43 },
  { "MIPSepCuts", intFirstGUROBIPar + 44 },
  { "MIRCuts", intFirstGUROBIPar + 45 },
  { "StrongCGCuts", intFirstGUROBIPar + 46 },
  { "NetworkCuts", intFirstGUROBIPar + 47 },
  { "SubMIPCuts", intFirstGUROBIPar + 48 },
  { "ZeroHalfCuts", intFirstGUROBIPar + 49 },
  { "ModKCuts", intFirstGUROBIPar + 50 },
  { "InfProofCuts", intFirstGUROBIPar + 51 },
  { "RLTCuts", intFirstGUROBIPar + 52 },
  { "RelaxLiftCuts", intFirstGUROBIPar + 53 },
  { "BQPCuts", intFirstGUROBIPar + 54 },
  { "PSDCuts", intFirstGUROBIPar + 55 },
  { "LiftProjectCuts", intFirstGUROBIPar + 56 },
  { "ServerTimeout", intFirstGUROBIPar + 57 },
  { "CSPriority", intFirstGUROBIPar + 58 },
  { "CSIdleTimeout", intFirstGUROBIPar + 59 },
  { "CSTLSInsecure", intFirstGUROBIPar + 60 },
  { "TSPort", intFirstGUROBIPar + 61 },
  { "CSBatchMode", intFirstGUROBIPar + 62 },
  { "CSClientLog", intFirstGUROBIPar + 63 },
  { "WLSTokenDuration", intFirstGUROBIPar + 64 },
  { "LicenseID", intFirstGUROBIPar + 65 },
  { "Aggregate", intFirstGUROBIPar + 66 },
  { "AggFill", intFirstGUROBIPar + 67 },
  { "PreDual", intFirstGUROBIPar + 68 },
  { "ConcurrentMIP", intFirstGUROBIPar + 69 },
  { "ConcurrentJobs", intFirstGUROBIPar + 70 },
  { "DisplayInterval", intFirstGUROBIPar + 71 },
  { "DistributedMIPJobs", intFirstGUROBIPar + 72 },
  { "DualReductions", intFirstGUROBIPar + 73 },
  { "IISMethod", intFirstGUROBIPar + 74 },
  { "InfUnbdInfo", intFirstGUROBIPar + 75 },
  { "JSONSolDetail", intFirstGUROBIPar + 76 },
  { "LogToConsole", intFirstGUROBIPar + 77 },
  { "MIQCPMethod", intFirstGUROBIPar + 78 },
  { "NonConvex", intFirstGUROBIPar + 79 },
  { "NumericFocus", intFirstGUROBIPar + 80 },
  { "QCPDual", intFirstGUROBIPar + 81 },
  { "PreCrush", intFirstGUROBIPar + 82 },
  { "PreDepRow", intFirstGUROBIPar + 83 },
  { "PreQLinearize", intFirstGUROBIPar + 84 },
  { "PrePasses", intFirstGUROBIPar + 85 },
  { "Presolve", intFirstGUROBIPar + 86 },
  { "PreSOS1Encoding", intFirstGUROBIPar + 87 },
  { "PreSOS2Encoding", intFirstGUROBIPar + 88 },
  { "PreSparsify", intFirstGUROBIPar + 89 },
  { "PreMIQCPForm", intFirstGUROBIPar + 90 },
  { "Seed", intFirstGUROBIPar + 91 },
  { "SolutionTarget", intFirstGUROBIPar + 92 },
  { "Threads", intFirstGUROBIPar + 93 },
  { "LazyConstraints", intFirstGUROBIPar + 94 },
  { "TuneResults", intFirstGUROBIPar + 95 },
  { "TuneCriterion", intFirstGUROBIPar + 96 },
  { "TuneTrials", intFirstGUROBIPar + 97 },
  { "TuneOutput", intFirstGUROBIPar + 98 },
  { "TuneJobs", intFirstGUROBIPar + 99 },
  { "TuneMetric", intFirstGUROBIPar + 100 },
  { "UpdateMode", intFirstGUROBIPar + 101 },
  { "ObjNumber", intFirstGUROBIPar + 102 },
  { "MultiObjMethod", intFirstGUROBIPar + 103 },
  { "MultiObjPre", intFirstGUROBIPar + 104 },
  { "ScenarioNumber", intFirstGUROBIPar + 105 },
  { "Record", intFirstGUROBIPar + 106 },
  { "PoolSolutions", intFirstGUROBIPar + 107 },
  { "PoolSearchMode", intFirstGUROBIPar + 108 },
  { "IgnoreNames", intFirstGUROBIPar + 109 },
  { "StartNumber", intFirstGUROBIPar + 110 },
  { "PartitionPlace", intFirstGUROBIPar + 111 },
  { "FuncPieces", intFirstGUROBIPar + 112 },
  { "OutputFlag", intFirstGUROBIPar + 113 },
 }
};

const std::array< std::pair< std::string, int >, GRB_NUM_DBL_PARS >
 GRBMILPSolver::GUROBI_to_SMSpp_dbl_pars{
 {
  { "Cutoff", dblFirstGUROBIPar + 0 },
  { "IterationLimit", dblFirstGUROBIPar + 1 },
  { "NodeLimit", dblFirstGUROBIPar + 2 },
  { "TimeLimit", dblFirstGUROBIPar + 3 },
  { "WorkLimit", dblFirstGUROBIPar + 4 },
  { "MemLimit", dblFirstGUROBIPar + 5 },
  { "SoftMemLimit", dblFirstGUROBIPar + 6 },
  { "BestObjStop", dblFirstGUROBIPar + 7 },
  { "BestBdStop", dblFirstGUROBIPar + 8 },
  { "FeasibilityTol", dblFirstGUROBIPar + 9 },
  { "IntFeasTol", dblFirstGUROBIPar + 10 },
  { "MarkowitzTol", dblFirstGUROBIPar + 11 },
  { "MIPGap", dblFirstGUROBIPar + 12 },
  { "MIPGapAbs", dblFirstGUROBIPar + 13 },
  { "OptimalityTol", dblFirstGUROBIPar + 14 },
  { "PSDTol", dblFirstGUROBIPar + 15 },
  { "PerturbValue", dblFirstGUROBIPar + 16 },
  { "ObjScale", dblFirstGUROBIPar + 17 },
  { "BarConvTol", dblFirstGUROBIPar + 18 },
  { "BarQCPConvTol", dblFirstGUROBIPar + 19 },
  { "Heuristics", dblFirstGUROBIPar + 20 },
  { "NodefileStart", dblFirstGUROBIPar + 21 },
  { "NoRelHeurTime", dblFirstGUROBIPar + 22 },
  { "NoRelHeurWork", dblFirstGUROBIPar + 23 },
  { "CSQueueTimeout", dblFirstGUROBIPar + 24 },
  { "WLSTokenRefresh", dblFirstGUROBIPar + 25 },
  { "PreSOS1BigM", dblFirstGUROBIPar + 26 },
  { "PreSOS2BigM", dblFirstGUROBIPar + 27 },
  { "FeasRelaxBigM", dblFirstGUROBIPar + 28 },
  { "ImproveStartTime", dblFirstGUROBIPar + 29 },
  { "ImproveStartGap", dblFirstGUROBIPar + 30 },
  { "ImproveStartNodes", dblFirstGUROBIPar + 31 },
  { "TuneTimeLimit", dblFirstGUROBIPar + 32 },
  { "TuneCleanup", dblFirstGUROBIPar + 33 },
  { "TuneTargetMIPGap", dblFirstGUROBIPar + 34 },
  { "TuneTargetTime", dblFirstGUROBIPar + 35 },
  { "PoolGap", dblFirstGUROBIPar + 36 },
  { "PoolGapAbs", dblFirstGUROBIPar + 37 },
  { "FuncPieceLength", dblFirstGUROBIPar + 38 },
  { "FuncPieceError", dblFirstGUROBIPar + 39 },
  { "FuncPieceRatio", dblFirstGUROBIPar + 40 },
  { "FuncMaxVal", dblFirstGUROBIPar + 41 },
 }
};

const std::array< std::pair< std::string, int >, GRB_NUM_STR_PARS >
 GRBMILPSolver::GUROBI_to_SMSpp_str_pars{
 {
  { "NodefileDir", strFirstGUROBIPar + 0 },
  { "SolFiles", strFirstGUROBIPar + 1 },
  { "WorkerPool", strFirstGUROBIPar + 2 },
  { "WorkerPassword", strFirstGUROBIPar + 3 },
  { "ComputeServer", strFirstGUROBIPar + 4 },
  { "JobID", strFirstGUROBIPar + 5 },
  { "CSRouter", strFirstGUROBIPar + 6 },
  { "CSGroup", strFirstGUROBIPar + 7 },
  { "ServerPassword", strFirstGUROBIPar + 8 },
  { "TokenServer", strFirstGUROBIPar + 9 },
  { "CloudAccessID", strFirstGUROBIPar + 10 },
  { "CloudSecretKey", strFirstGUROBIPar + 11 },
  { "CloudPool", strFirstGUROBIPar + 12 },
  { "CloudHost", strFirstGUROBIPar + 13 },
  { "CSManager", strFirstGUROBIPar + 14 },
  { "CSAuthToken", strFirstGUROBIPar + 15 },
  { "CSAPIAccessID", strFirstGUROBIPar + 16 },
  { "CSAPISecret", strFirstGUROBIPar + 17 },
  { "Username", strFirstGUROBIPar + 18 },
  { "CSAppName", strFirstGUROBIPar + 19 },
  { "WLSAccessID", strFirstGUROBIPar + 20 },
  { "WLSSecret", strFirstGUROBIPar + 21 },
  { "WLSToken", strFirstGUROBIPar + 22 },
  { "LogFile", strFirstGUROBIPar + 23 },
  { "ResultFile", strFirstGUROBIPar + 24 },
  { "Dummy", strFirstGUROBIPar + 25 },
 }
};
