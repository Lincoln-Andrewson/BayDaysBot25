#include "subsystems/StupidFunctions.h"
#include <frc/controller/PIDController.h>


StupidFunctions::StupidFunctions(){
        
}

void StupidFunctions::Periodic(){

}

double StupidFunctions::randomStickDrift(int axis) {
    //Gradually shifts randomAdder value, and if it gets too close to 0, reset it to something random
    // The frequency may need to be changed to what is best
    if(stupidModeActive == true){
        if(drunkModulusCounter % 200 == 0){
                if(axis == 0){
                    if(frc::ApplyDeadband(randomAdderX, 0.02) >= 0){
                        randomAdderX = randomAdderX - 0.05;
                    } else if(frc::ApplyDeadband(randomAdderX, 0.02) <= 0){
                        randomAdderX = randomAdderX + 0.05;
                    } else {
                        randomAdderX = rand() / RAND_MAX;
                    }
                    return randomAdderX;

            } else if(axis == 1){
                    if(frc::ApplyDeadband(randomAdderY, 0.02) >= 0){
                        randomAdderY = randomAdderY - 0.05;
                    } else if(frc::ApplyDeadband(randomAdderY, 0.02) <= 0){
                        randomAdderY = randomAdderY + 0.05;
                    } else {
                        randomAdderY = rand() / RAND_MAX;
                    }
                    return randomAdderY;
            } else {
                return 0.0;
            }
            drunkModulusCounter++;
        } else if (axis == 0){
            return randomAdderX;
        } else if (axis == 1){
            return randomAdderY;
        }
    }
}
void constructiveCriticismKill(){
    frc::SmartDashboard::PutBoolean("HAHAHAHA DEAD", "yup");
}
void StupidFunctions::constructiveCriticism(frc::XboxController& driverController){  
    if(stupidModeActive == true){
        srand(time(NULL)); // Randomizes the random
        if(!criticismStalled){
            if(criticismCounter >= criticismCycles){  // If critismCounter is over the max time, reset it
                criticismCounter = 0;
            } 
            if(criticismCounter == 0){ // Set the random on the first pass
                criticismRand = ((double)rand() / RAND_MAX)*criticismCycles; 
            }

            if(frc::ApplyDeadband(criticismRand-criticismCounter, StupidFunctionsConstants::kRumbleLength) == 0){ // If the counter is in between a range (rumble length) of the random point, rumble controller 
                driverController.SetRumble(driverController.kBothRumble, 1);
                frc::SmartDashboard::PutNumber("Rumble", 1);
                //criticismStalled = true;

            } else{  // Otherwise stop rumbling controller
                driverController.SetRumble(driverController.kBothRumble, 0);
                frc::SmartDashboard::PutNumber("Rumble", 0);
            }

            frc::SmartDashboard::PutNumber("Random", criticismRand);
            frc::SmartDashboard::PutNumber("Counter", criticismCounter);
            frc::SmartDashboard::PutBoolean("Stalled", criticismStalled);
            criticismCounter++;

        } else{ // I don't even know
            driverController.SetRumble(driverController.kBothRumble, 0);
            frc::SmartDashboard::PutString("Did you screw up?!?!?", "Fibler Text");
            frc::SmartDashboard::PutData("Yes :(", new frc2::RunCommand([this] {constructiveCriticismKill();}));
            frc::SmartDashboard::PutData("No :D", new frc2::RunCommand([this] {criticismStalled=false;}));
        }
    }
};