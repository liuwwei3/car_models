// a simple apple plugin 
// author : liuweiwei <liuweiwei02@baidu.com>

#include <boost/bind.hpp>
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/gazebo.hh>
#include <stdio.h>

namespace gazebo {

class ApplePlugin : public ModelPlugin {

public:
    void Load( physics::ModelPtr _model, sdf::ElementPtr _element){
        this->model = _model;
        this->upconn = event::Events::ConnectWorldUpdateBegin(
            boost::bind( &ApplePlugin::onUpdate, this, _1));
    }

    void onUpdate(const common::UpdateInfo _info) {
        // model on update, nothing todo ...
        // update rate: perhaps 100hz
        //this->model->SetLinearVel(math::Vector3(0.0, 0, 0.05));
    }

private:
    physics::ModelPtr model;
    event::ConnectionPtr upconn;
};

GZ_REGISTER_MODEL_PLUGIN(ApplePlugin);

}
