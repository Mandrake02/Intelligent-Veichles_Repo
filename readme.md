# Intelligent Vehicles and Autonomous Driving

This repository contains the project developed for the university course **Intelligent Vehicles and Autonomous Driving**, taught by **Gastone Pietro Rosati Papini**.

The project is organized around two communicating components:

- **Agent**: a C/C++ autonomous-driving agent that implements the vehicle control logic.
- **PyDrivingSim**: a Python driving simulator that provides the environment in which the agent operates.

The simulator can be used to test high-level and low-level control algorithms in autonomous-driving scenarios, including traffic lights, speed limits, vehicles, and collectible objects.

## Repository Structure

```text
.
├── Agent/
│   ├── starting_point.cc       # Agent entry point
│   ├── CMakeLists.txt          # Agent build configuration
│   ├── lib/                    # Platform-specific communication libraries
│   └── log/                    # Logging utilities
├── PyDrivingSim/
│   ├── simulator.py            # Simulator entry point
│   ├── agent/                  # Python-side agent communication interfaces
│   ├── pydrivingsim/           # Simulator objects and world model
│   ├── scenarios/              # Available driving scenarios
│   └── vehicle_model/          # Vehicle dynamics models
└── Reference/                  # Reference implementation and documentation
```

## Requirements

- Python 3
- `pip` and Python virtual-environment support
- CMake 3.5 or newer
- A C++11-compatible compiler
- Platform-specific communication libraries from `Agent/lib`

## Environment Setup

From the `PyDrivingSim` directory, create and activate a virtual environment and install the Python dependencies:

### macOS and Linux

```bash
cd PyDrivingSim
python3 -m venv .venv
source .venv/bin/activate
pip install -r requirements.txt
```

### Windows

```powershell
cd PyDrivingSim
py -3 -m venv .venv
.venv\Scripts\activate
pip install -r requirements.txt
```

Run the simulator with:

```bash
python simulator.py
```

For platform-specific notes, including the WSL display configuration, see [PyDrivingSim/README.md](PyDrivingSim/README.md).

## Agent Setup and Build

Before building the Agent, copy the communication library for the target platform from its subdirectory under `Agent/lib` into the `Agent/lib` directory. The available library directories include:

- `linux` and `linux_fPIC`
- `macos` and `macos_x86`
- `win_mingw`
- `win_visual_studio` and `win_visual_studio_x86`
- `win_wsl`

On macOS or Linux, build the Agent from its directory with:

```bash
cd Agent
cmake .
make
```

The same project can also be opened and built with CLion or another IDE with CMake support. Windows-specific setup instructions are available in [Agent/README.md](Agent/README.md).

## Running the Project

1. Configure the Python environment for `PyDrivingSim`.
2. Select the appropriate communication library for the current operating system.
3. Build the C/C++ Agent.
4. Start the simulator and the Agent according to the communication setup.
5. Use the scenarios in `PyDrivingSim/scenarios` to evaluate the agent's behavior.

The main simulator entry point is `PyDrivingSim/simulator.py`, while the Agent entry point is `Agent/starting_point.cc`.

## Course Context

This project provides a practical environment for studying autonomous-vehicle control, vehicle dynamics, and the interaction between a driving environment and an external control agent.
