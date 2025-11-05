#include "subsystems/Shooter.h"

Shooter::Shooter(){

}

void Shooter::Periodic(){

}

void Shooter::SetShooterSpeed(double speed){ //Speed should be 0-1, indicating 0-100%
        m_leftShooterMotor.Set(kLeftShooterSpeed * speed);
        m_rightShooterMotor.Set(kRightShooterSpeed * speed); //motors must be in alternating directions, but left is flipped upside down, so yeah
}