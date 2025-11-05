#pragma once

#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

using namespace rev::spark;
using namespace ShooterConstants;

class Shooter : public frc2::SubsystemBase {
    public:
        Shooter();

        void Periodic() override;

        void SetShooterSpeed(double speed);

    private:
        SparkMax m_leftShooterMotor{kLeftShooterMotorCanID, SparkLowLevel::MotorType::kBrushless};
        SparkMax m_rightShooterMotor{kRightShooterMotorCanID, SparkLowLevel::MotorType::kBrushless};
    
};