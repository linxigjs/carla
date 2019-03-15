// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/road/Road.h"
#include "carla/road/Lane.h"
#include "carla/road/MapData.h"

#include <boost/optional.hpp>

namespace carla {
namespace road {

  MapData *Road::GetMap() const {
    return _map_data;
  }

  RoadId Road::GetId() const {
    return _id;
  }

  bool Road::IsJunction() const {
    return _is_junction;
  }

  JuncId Road::GetJunction() const {
    return _junction_id;
  }

  std::vector<Road *> Road::GetNexts() const {
    std::vector<Road *> vec;
    for (auto &&next : _nexts) {
      vec.emplace_back(_map_data->GetRoad());
    }
    return vec;
  }

  std::vector<Road *> Road::GetPrevs() const{

  }

  // const Lane *GetLane(const LaneId id, float s) const {
  //   const auto lanes = _lane_sections.GetReverseSubset(s);
  //   return lanes.size() > 0 ? lanes.begin() : nullptr;
  // }

} // road
} // carla