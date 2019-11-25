/*
Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
*/
#include "HardSoftLogicMixer.hpp"
#include <iostream>
#include <vector>
#include "OdinGridAnalyzer.hpp"

HardSoftLogicMixer::HardSoftLogicMixer(const t_arch& arch,int config):_analyzer(),_arch(arch){
	_allOptsDisabled = true;
	// By default, disables all optimizations, starts from 1
	for (int i = 0; i < HardBlocksOptimizationTypesEnum::Count; i++){
		_enabledOptimizations[i] = false;
	}

	parseAndSetOptimizationParameters(config);
}

void HardSoftLogicMixer::parseAndSetOptimizationParameters(int config){
	if (config!=0){
	int checkValue = -1;
		for (int i = HardBlocksOptimizationTypesEnum::Count-1; i>0; i--){
			checkValue = config - i;
			if (checkValue >= 0){
				_enabledOptimizations[i] = true;
				config = config - i;
			}
		}
		_allOptsDisabled = false;
	}
}

void HardSoftLogicMixer::calculateAllGridSizes(){
	if (true ==_allOptsDisabled)
	{
		std::cerr<<"ODIN won't continue execution of calculateAllGridSizes()"<<
					"since it should not optimize at all";
		exit(6);
	}		
	for (int i = 0 ; i < _arch.grid_layouts.size();i++)
	{
		const t_grid_def& ref =   _arch.grid_layouts[i];
		std::pair<int,int> widthAndHeight = _analyzer.estimatePossibleDeviceSize(ref);
		_grid_layout_sizes.emplace(i,widthAndHeight);
		
	}
	
}
void HardSoftLogicMixer::takeNoteOfAPotentialHardBlockNode( nnode_t * multNode, HardBlocksOptimizationTypesEnum type){
	potentialHardBlockNodes[type].emplace_back(multNode);
}
void HardSoftLogicMixer::selectLogicToImplementInHardBlocks(netlist_t *netlist){
	for (int i = 1; i < )
	if (_enabledOptimizations[]){
		std::vectorvectorOf
		instantiate_simple_soft_multiplier( _multiplierNodes[0], PARTIAL_MAP_TRAVERSE_VALUE, netlist);
		instantiate_simple_soft_multiplier( _multiplierNodes[1], PARTIAL_MAP_TRAVERSE_VALUE, netlist);
	}
}