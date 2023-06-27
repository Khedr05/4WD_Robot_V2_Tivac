# 4WD_Robot_V2_Tivac
![WhatsApp Image 2023-05-20 at 14 05 24](https://github.com/sherifkhadr/SPRINTS_Obstacle_Car_Avoidance/assets/60091384/95f43bdf-e554-47d3-b05d-6b227aefff78)


## Static Design Project
### Brief
> - Embedded C application controlling a four-diving wheel robot, so that the car moves in a rectangular shape, based on TivaC launchpad.

#### Author: Team_5 

|     Members    |        🔗 [GitHub] Links               |
|----------------| --------------------------------------- |
|     Sherif     | (https://github.com/sherifkhadr)        |
|     Sharpel    | (https://github.com/sharpelmalak)       |
|     Moamen     | (https://github.com/MomenHassan12)      |
|     Mowafey    | (https://github.com/Mahmoud-Mowafy)     |

## Documentation
> - `Project Documentation`
        [Google Doc](https://docs.google.com/document/d/1IRe-8jyH7wxBTIzXYDLSMfOx0oQpCD-H/edit#heading=h.jicq1xxnfydk)
        [PDF]()
> - `Team Backlog` 
        [Google Sheets](https://docs.google.com/spreadsheets/d/1KqM43krTIfqdNmvoGyEEz4QNa8kiRKZ9E0DTX5FQSQ4/edit#gid=0) 
        [PDF](https://drive.google.com/drive/folders/1CXbXtSQmKKQIm5jPsotvxY5uF6XswF_j)
> - `Test Protocol` 
      [Google Sheets]() 
      [PDF]()
> - `Video & Simulation_Test` 
      [Videos]() 
> - ---





#### System Requirement Specifications
    1. AC Components:
      1- Use Sprints Kit with TivaC launch pad plugged in
      2- You will develop your application on the ARM microcontroller
      3- Four motors (M1, M2, M3, M4)
      4- One button to start (PB1)
      5- One button for stop (PB2)
      6- Four LEDs (LED1, LED2, LED3, LED4)
    
    2. System Requirements:
      1- The car starts initially from 0 speed
      2- When PB1  is pressed, the car will move forward after 1 second
      3- The car will move forward to create the longest side of the rectangle for 3 seconds with 50% of its maximum speed
      4- After finishing the first longest side the car will stop for 0.5 seconds, rotate 90 degrees to the right, and stop for 0.5 second
      5- The car will move to create the short side of the rectangle at 30% of its speed for 2 seconds
      6- After finishing the shortest side, the car will stop for 0.5 seconds, rotate 90 degrees to the right, and stop for 0.5 second
      7- Steps 3 to 6 will be repeated infinitely until you press the stop button (PB2)
      8- PB2 acts as a sudden break, and it has the highest priority
      9- LEDs Operations
        1. LED1: On means moving forward on the long side
        2. LED2: On means moving forward on the short side
        3. LED3: On means stop
        4. LED4: On means Rotating


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Layered Architecture & System Modules
![obs_avoi_rob_LAyered Arch](https://github.com/sherifkhadr/4WD_Robot_V2_Tivac/assets/60091384/7e4f470c-2fcb-4a9b-86de-d570dd4a5b8a)


-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
## Object Files
> - ` Hex_file`[Hex_file]()



