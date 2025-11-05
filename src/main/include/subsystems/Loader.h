#pragma once
#include <frc2/command/SubsystemBase.h>
#include "Constants.h"

using namespace rev::spark;
using namespace LoaderConstants;

class Loader : public frc2::SubsystemBase {
    public:
        Loader();

        void RunLoader();
        void StopLoader();
        void Periodic() override;

    private:
        SparkMax m_loaderMotor{kLoaderMotorCanID, SparkLowLevel::MotorType::kBrushless};
};