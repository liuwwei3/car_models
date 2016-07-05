// a simple car model plugin 
// author : liuweiwei <liuweiwei02@baidu.com>

#include <boost/bind.hpp>
#include <gazebo/common/common.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/gazebo.hh>
#include <ignition/math.hh>
#include <stdio.h>

namespace gazebo {

class CarPlugin : public ModelPlugin {

public:
    void Load( physics::ModelPtr _model, sdf::ElementPtr _element){
        physics::LinkPtr applebody = _model->GetChildLink("applebody");
        physics::InertialPtr _inertial(new physics::Inertial(1.0));
        applebody->SetInertial(_inertial);
        
        this->model = _model;
        this->upconn = event::Events::ConnectWorldUpdateBegin(
            boost::bind( &ApplePlugin::onUpdate, this, _1));
    }

    void onUpdate(const common::UpdateInfo _info) {
        // update rate: perhaps 100hz
        //this->model->SetLinearVel(math::Vector3(0.0, 0, 0.05));
        this->model->GetChildLink("applebody")->AddForceAtRelativePosition( \
            math::Vector3(0.0, 0, 0.0), math::Vector3(0.1, 0, 0.5));
    }

private:
    physics::ModelPtr model;
    event::ConnectionPtr upconn;
};

GZ_REGISTER_MODEL_PLUGIN(ApplePlugin);

}
