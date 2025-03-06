# Virtual World Simulator

> A virtual world simulator with a two-dimensional grid structure, populated with various life forms that interact with each other according to specific rules.

## Description

The simulation is turn-based, with each organism performing actions appropriate to its type. Some organisms move (animals), while others remain stationary (plants). When organisms collide, one wins by killing or repelling the competitor based on strength and special abilities.

## Game Mechanics

- The world is a 2D grid of size N×M (20×20 for basic implementation)
- Each organism occupies exactly one cell, with no more than one organism per cell
- Turn order is determined by initiative (higher goes first)
- In case of equal initiative, seniority decides (older organisms go first)
- Collisions result in fight, with the stronger organism usually winning
- Special abilities and exceptions to basic rules make gameplay more interesting

## Organisms

### Hierarchy

```
Organism (Abstract)
├── Animal (Abstract)
│   ├── Human
│   ├── Wolf
│   ├── Sheep
│   ├── Fox
│   ├── Turtle
│   ├── Antelope
│   └── CyberSheep
└── Plant (Abstract)
    ├── Grass
    ├── Dandelion
    ├── Guarana
    ├── Nightshade
    └── SosnowskyHogweed
```

### Animals

| Animal | Strength | Initiative | Special Abilities |
|--------|----------|------------|-------------------|
| Wolf | 9 | 5 | None |
| Sheep | 4 | 4 | None |
| Fox | 3 | 7 | Good smell: never moves to fields occupied by stronger organisms |
| Turtle | 2 | 1 | 75% chance to stay in place; repels attacks from animals with strength <5 |
| Antelope | 4 | 4 | Movement range of 2 cells; 50% chance to escape from fight |
| CyberSheep | 11 | 4 | Prioritizes hunting Sosnowsky's Hogweed; behaves like a regular sheep if no hogweed exists |

### Plants

| Plant | Strength | Special Abilities |
|-------|----------|-------------------|
| Grass | 0 | None |
| Dandelion | 0 | Makes three spreading attempts per turn |
| Guarana | 0 | Increases strength of the animal that eats it by 3 |
| Nightshade | 99 | Kills any animal that eats it |
| Sosnowsky's Hogweed | 10 | Kills all animals in adjacent cells except CyberSheep; kills any animal that eats it except CyberSheep |

### Human

The Human is a special organism controlled by the player:
- Movement via arrow keys
- Strength: 5
- Initiative: 4
- Special ability (activated by a key) that remains active for 5 turns, followed by 5 turns cooldown

## Human Special Abilities

The Human's special ability is determined by the student's ID:

| ID | Ability | Effect |
|----|---------|--------|
| 0 | Immortality | Cannot be killed; moves to a random adjacent cell when confronted by a stronger opponent |
| 1 | Magic Elixir | Strength increases to 10 in the first turn, then decreases by 1 each turn until back to normal |
| 2 | Antelope Speed | Moves 2 cells instead of 1 for the first 3 turns; 50% chance to work in the last 2 turns |
| 3 | Alzur's Shield | Repels all animals; animals that step on Human's position are moved to a random adjacent cell |
| 4 | Burning | Destroys all plants and animals in adjacent cells |

## Implementation Requirements

### Core Classes

#### World Class
- Methods: `executeTurn()`, `drawWorld()`
- Fields: `organisms`

#### Organism Class (Abstract)
- Fields: `strength`, `initiative`, `position (x,y)`, `world` (reference)
- Methods: `action()`, `collision()`, `draw()`

### Console Interface

- Each organism is represented by a unique ASCII symbol
- Key press advances to the next turn
- At least one line of text reports events like eating or fighting outcomes

### Features by Grade Level

#### Grade 3
- World implementation and visualization
- All required animal species (without breeding)
- All plant species (without spreading)
- Human controlled by arrow keys

#### Grade 4
- All Grade 3 requirements
- Animal breeding and plant spreading
- Human special ability implementation

#### Grade 5
- All Grade 4 requirements
- Save/load world state to/from file
