#ifndef TestWorkspaces_h
#define TestWorkspaces_h

#include <RooStats/HistFactory/HistoToWorkspaceFactoryFast.h>

class RooWorkspace;

namespace TestWorkspaces {

RooWorkspace *getWorkspace001(RooStats::HistFactory::HistoToWorkspaceFactoryFast::Configuration const &cfg);

} // namespace TestWorkspaces

#endif
