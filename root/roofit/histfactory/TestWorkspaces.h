#ifndef TestWorkspaces_h
#define TestWorkspaces_h

#include <RooStats/HistFactory/HistoToWorkspaceFactoryFast.h>

#include <memory>

class RooWorkspace;

namespace TestWorkspaces {

std::unique_ptr<RooWorkspace>
getWorkspace001(RooStats::HistFactory::HistoToWorkspaceFactoryFast::Configuration const &cfg);

} // namespace TestWorkspaces

#endif
