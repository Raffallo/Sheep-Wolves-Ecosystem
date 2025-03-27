# Wolves and Sheep Simulation

A C++ simulation where wolves and sheep interact within a grid-based environment.
Wolves must eat sheep to survive and reproduce, while sheep try to survive and multiply.
The simulation includes animal behaviors, reproduction rules, and statistics tracking.

---

## How It Works

1. **Tile System:** 
   - Each tile contains a `CellData` struct that stores the animals present.
   - Wolves and sheep are stored in separate vectors.

2. **Animal Simulation:**
   - Wolves eat one sheep per iteration if available.
   - Wolves that survive and encounter another wolf of the opposite gender reproduce.
   - Sheep reproduce if a male and a female sheep coexist on the same tile.

3. **Statistics:**
   - After each iteration, a concise summary is printed:
     ```
     Iteration: x Total Animals: x (Wolves: x [M: x, F: x], Sheep: x [M: x, F: x])
     ```
