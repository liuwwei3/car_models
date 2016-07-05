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
        this->frwheel = _model->GetChildLink("FRwheel");
        this->flwheel = _model->GetChildLink("FLwheel");
        
        this->model = _model;
        this->upconn = event::Events::ConnectWorldUpdateBegin(
            boost::bind( &CarPlugin::onUpdate, this, _1));
    }

    void onUpdate(const common::UpdateInfo _info) {
        // update rate: perhaps 100hz
        this->frwheel->AddRelativeTorque(math::Vector3(0,1,0));
        this->flwheel->AddRelativeTorque(math::Vector3(0,1,0));
    }

private:
    physics::ModelPtr model;
    event::ConnectionPtr upconn;
    physics::LinkPtr frwheel;
    physics::LinkPtr flwheel;
};

GZ_REGISTER_MODEL_PLUGIN(CarPlugin);

}
