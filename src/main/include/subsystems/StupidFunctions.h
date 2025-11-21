#pragma once

#include <frc2/command/SubsystemBase.h>
#include <frc2/command/RunCommand.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class StupidFunctions : public frc2::SubsystemBase {
    public:
        StupidFunctions();

        void Periodic() override;

        double randomStickDrift(int axis);
        void constructiveCriticism(frc::XboxController& driverController);
        void constructiveCritismKill();

    private:
        int drunkModulusCounter = 0;
        double randomAdderX;
        double randomAdderY;
        
        int criticismCycles = StupidFunctionsConstants::kMaxCritismSeconds*50;
        long criticismRand = 0;
        int criticismCounter = -1;
        bool criticismStalled = false;
        

        bool stupidModeActive = true;
    
};