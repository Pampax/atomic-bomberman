# Big Maps

**Not in the original.** The original's field is always 15 x 11 cells. This mode is a design of this project; nothing here was observed on the original, and a match on the normal size is untouched by it (the same random draws, the same state bytes).

## What a big map is

The chosen level and scheme, repeated side by side: 2 x 2 (30 x 22 cells) or 3 x 3 (45 x 33 cells). It is chosen for a local match under *Map size* on the screen with the level and the scheme, or with `--map-size N`, and kept with the settings (`map_repeat`). Campaign stages, the demo round and network games always use the normal size.

## Rules

| What | On a big map | Why |
|---|---|---|
| Field | Each copy is the scheme's own layout, with bricks drawn cell by cell at the scheme's density | |
| Start cells | Each player uses its own start cell, in a copy of the field of its own: first the corners, then the middle, then the rest. An eleventh player would share a copy | Players start spread out, however few there are |
| Hidden powerups | The level's count, once per copy | The same density |
| Level features | Arrows, conveyors, warps and trampolines repeat with the field. A warp leads to its partner in the same copy | |
| Round clock | The play time times the copies across (3 x 3: 2:30 becomes 7:30). "No limit" stays so | The map takes that many times longer to cross |
| Hurry | From 60 s left, as usual | |
| Closing walls | From 55 s left, as usual. Rings: the depth setting's, times the copies across. One cell every 250 ms / number of copies | The same share of the map closes in about the same time |
| Brick regrowth | The level's interval / number of copies | The same pace per copy |
| Goldflame | Reaches the longer side of the map | As on the normal size |
| Bombs off the edge | Come back on the far side of the whole map | As on the normal size |
| Computer players | Behave as on the normal size. They see the closing walls as far ahead in time (more cells) | Their searches still reach 20 steps, so a far enemy is ignored until it comes near |

## On the screen

A cell has the same size on the screen as on the normal map. The view shows as much of the map as fits, under a band with the clock and the labels (a phone's wide screen shows about 26 x 12 cells).

- One player on this device: the view follows that player, up to the map's edges.
- Several: the view takes in all of them, going as far out as the whole map if it must.
- None left in play (or only computer players): the view takes in everybody still alive.

## Limits at present

- Ten players at most, as on the normal size.
- Local matches only.
- The maps are repetitions: a scheme file still describes one 15 x 11 field.
