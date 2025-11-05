#include "subsystems/Loader.h"

Loader::Loader() {
    // Constructor implementation
}

void Loader::RunLoader() {
    m_loaderMotor.Set(kLoaderSpeed);
}

void Loader::StopLoader() {
    m_loaderMotor.Set(0.0); // Stop the loader motor
}

void Loader::Periodic() {
    // Periodic method implementation, if needed
    // This method is called periodically by the scheduler
};