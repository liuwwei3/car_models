// a world plugin that gravity = (0, 0, 0.05)
// author: liuweiwei02 <liuweiwei02@baidu.com>

#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/gazebo.hh>
#include <ignition/math/Pose3.hh>
#include <stdio.h>

namespace gazebo {

class AppleWorldPlugin: public WorldPlugin {

public:
    void Load(physics::WorldPtr _world, sdf::ElementPtr _ele ){
        _world->InsertModelFile("model://apple");
        printf("mow loading world plugin...\n");
        _world->SetGravity(ignition::math::Vector3d(0, 0, 0.05));
    }

};

GZ_REGISTER_WORLD_PLUGIN(AppleWorldPlugin);

}
