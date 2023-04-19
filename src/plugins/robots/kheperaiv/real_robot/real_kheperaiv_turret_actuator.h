#ifndef REAL_KHEPERAIV_TURRET_ACTUATOR_H
#define REAL_KHEPERAIV_TURRET_ACTUATOR_H

#include <argos3/core/utility/math/angles.h>
#include <argos3/plugins/robots/kheperaiv/real_robot/real_kheperaiv_device.h>
#include <argos3/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_actuator.h>
#include "cgripperI2C.h"

using namespace argos;

class CRealKheperaIVTurretActuator :
   // public CCI_KheperaIVTurretActuator,
   public CCI_Actuator,
   public CRealKheperaIVDevice
   {

public:

   /** Turret modes */
   enum ETurretModes {
      MODE_OFF,
      MODE_PASSIVE,
      MODE_SPEED_CONTROL,
      MODE_POSITION_CONTROL
   };

//    static const CRange<SInt32> SPEED_RANGE;
//    static const CRange<Real>   NORMALIZED_SPEED_RANGE;

public:

   CRealKheperaIVTurretActuator(knet_dev_t* pt_dspic);
   // CRealKheperaIVTurretActuator();


   virtual ~CRealKheperaIVTurretActuator();

   virtual void Do(Real f_elapsed_time);

   /**
    * @brief Sets the turret rotation
    * Turret rotation is expressed in radians, positive values rotate the turret clockwise
    * when looking from above.
    * @param c_angle desired turret rotation
    */
   // virtual void SetRotation(const CRadians& c_angle) = 0;

   /**
    * @brief Sets the turret rotation speed
    * Turret rotation speed is expressed in motor pulses, positive values rotate the turret clockwise
    * when looking from above.
    * @param n_speed_pulses desired turret rotation speed - pid pulses
    */
   // virtual void SetRotationSpeed(SInt32 n_speed_pulses) = 0;

   /**
    * @brief Sets the turret control mode
    * Modes are: angular position control, rotation speed control, passive mode, off
    * @param un_mode turret control mode, possible values are defined in CCI_KheperaIVTurretActuator
    */
   // virtual void SetMode(ETurretModes e_mode) = 0;

private:
   ETurretModes m_eMode;
   short m_sEncoderCount;
   };

#endif
