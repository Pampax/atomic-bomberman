# Bigger Maps

**Not in the original.** The original's field is always 15 x 11 cells on a 4:3 screen. These maps are a design of this project; nothing here was observed on the original, and a match on the normal size in 4:3 is untouched by them (the same random draws, the same state bytes).

## Choosing a map

Two choices for a local match, on the screen with the level and the scheme (or `--map-size` and `--map-format`), kept with the settings (`map_size`, `map_format`). Campaign stages, the demo round and network games always use the normal field.

- **Map size** sets the number of rows, and with it how big a cell is on the screen.
- **Screen format** sets the number of columns, so that the map fills a screen of that shape.

| Cells (columns x rows) | 4:3 | 16:9 | 21:9 |
|---|---|---|---|
| **Normal** | 15 x 11 | 21 x 11 | 27 x 11 |
| **Medium** | 30 x 22 | 41 x 23 | 55 x 23 |
| **Big** | 45 x 33 | 59 x 33 | 79 x 33 |

**How the shapes come about.** Under the band for the labels (a tenth of the screen's height), with the field's frame and a cell's shape (40 x 36), a map exactly fills a screen when (columns + 1) / (rows + 1) is the screen's ratio. The classic field does so for 4:3 (16 / 12). In the wide formats the rows and columns are odd, which keeps a lane along every edge. What each gives, against the ratio it aims at:

| | 4:3 (1.333) | 16:9 (1.778) | 21:9 (2.333) |
|---|---|---|---|
| **Normal** | 1.333 | 1.833 (+3.1 %) | 2.333 |
| **Medium** | 1.348 (+1.1 %) | 1.750 (-1.6 %) | 2.333 |
| **Big** | 1.353 (+1.5 %) | 1.765 (-0.7 %) | 2.353 (+0.8 %) |

## Rules

| What | On a bigger map | Why |
|---|---|---|
| Field in 4:3 | Plain copies of the scheme's layout, side by side, with bricks drawn cell by cell at the scheme's density | |
| Field in a wide format | The layout folded over at its edges, as in a mirror: column 15 takes after column 13, and so on | Works for any number of cells, and the pillars stay in step across the whole map |
| Start cells in 4:3 | Each player uses its own start cell, in a copy of the field of its own: first the corners, then the middle, then the rest | Players start spread out, however few there are |
| Start cells in a wide format | Each start cell keeps its place, stretched to the map's size (corners stay corners); on a solid cell, it steps to the next free one | The same |
| Hidden powerups | The level's count, per classic field of surface | The same density |
| Level features | Arrows, conveyors, warps and trampolines repeat with the field. In a wide format they fold with it: an arrow points as in a mirror. A warp leads to its partner in the same copy, and a warp whose partner would lie outside the map is left out | |
| Round clock | The play time times the square root of the classic fields the map holds, rounded (Big in 4:3: 2:30 becomes 7:30). "No limit" stays so | The map takes that much longer to get round |
| Hurry | From 60 s left, as usual | |
| Closing walls | From 55 s left, as usual. Rings: the depth setting's, in proportion to the rows. One cell every 250 ms / the classic fields the map holds | About the same share of the map closes in about the same time |
| Brick regrowth | The level's interval / the classic fields the map holds | The same pace by surface |
| Goldflame | Reaches the longer side of the map | As on the normal size |
| Bombs off the edge | Come back on the far side of the whole map | As on the normal size |
| Computer players | Behave as on the normal size. They see the closing walls as far ahead in time (more cells) | Their searches still reach 20 steps, so a far enemy is ignored until it comes near |

## On the screen

All of the map is on the screen, all the time: no view that moves, no zoom. Under the band for the labels it is as big as the window allows, at the same scale both ways. On a screen of another shape than the chosen format, what is left over stays black.

## Limits at present

- Ten players at most, as on the normal size.
- Local matches only.
- A scheme file still describes one 15 x 11 field.
