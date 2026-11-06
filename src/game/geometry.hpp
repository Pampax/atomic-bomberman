// Grid geometry and coordinate conversions.
// Spec: docs/specifications/maps.md, docs/specifications/physics.md
#pragma once

#include <array>

namespace ab {

// The classic field, as the original has it and as scheme files describe it.
inline constexpr int kGridW = 15;
inline constexpr int kGridH = 11;
// The bigger maps on offer (docs/specifications/big-maps.md; not in the original). World::gridW()
// and gridH() say what a round uses. A map's size sets its rows, and so the size of a cell on
// the screen; its screen format sets its columns. With the band for the labels, the frame and
// the shape of a cell, a map fills a screen when (w + 1) / (h + 1) is that screen's ratio, as
// the classic field does 4:3. In the wide formats the columns are the odd number nearest to
// that, and rows and columns odd keep the pillars in step with a lane along every edge; the
// field is folded over at its edges to fill those maps, which keeps the pillars in step across
// them too. In 4:3 a bigger map is plain copies of the field.
struct MapShape {
    int w;
    int h;
    bool mirrored;  // the field folded over at its edges, instead of copies of it
};
inline constexpr std::array<const char*, 3> kMapSizeNames{"Normal", "Medium", "Big"};
inline constexpr std::array<const char*, 3> kMapFormatNames{"4:3", "16:9", "21:9"};
// By size, then by format.
inline constexpr std::array<std::array<MapShape, 3>, 3> kMapShapes{{
    {{{kGridW, kGridH, false}, {21, 11, true}, {27, 11, true}}},
    {{{kGridW * 2, kGridH * 2, false}, {41, 23, true}, {55, 23, true}}},
    {{{kGridW * 3, kGridH * 3, false}, {59, 33, true}, {79, 33, true}}},
}};
inline constexpr int kMaxGridW = 79;
inline constexpr int kMaxGridH = 33;
inline constexpr int kMaxCells = kMaxGridW * kMaxGridH;
inline constexpr int kCellW = 40;
inline constexpr int kCellH = 36;
inline constexpr int kOriginX = 20;
inline constexpr int kOriginY = 68;

// 0 north, 1 east, 2 south, 3 west; -1 none.
using Dir = int;
inline constexpr Dir kNoDir = -1;
inline constexpr std::array<int, 4> kDx{0, 1, 0, -1};
inline constexpr std::array<int, 4> kDy{-1, 0, 1, 0};

constexpr Dir opposite(Dir d) { return (d + 2) & 3; }
constexpr Dir turnRight(Dir d) { return (d + 1) & 3; }
constexpr Dir turnLeft(Dir d) { return (d + 3) & 3; }

struct Cell {
    int x = 0;
    int y = 0;
    friend constexpr bool operator==(Cell, Cell) = default;
};

constexpr Cell step(Cell c, Dir d) { return {c.x + kDx[static_cast<unsigned>(d)], c.y + kDy[static_cast<unsigned>(d)]}; }
// Inside the classic field (a scheme's own cells). During a round: World::inGrid.
constexpr bool inGrid(Cell c) { return c.x >= 0 && c.x < kGridW && c.y >= 0 && c.y < kGridH; }

// The cell of the classic field that a cell of a bigger map takes after.
constexpr Cell mapSourceCell(Cell c, bool mirrored) {
    if (!mirrored) return {c.x % kGridW, c.y % kGridH};
    const int periodX = 2 * (kGridW - 1), periodY = 2 * (kGridH - 1);
    const int x = c.x % periodX, y = c.y % periodY;
    return {x < kGridW ? x : periodX - x, y < kGridH ? y : periodY - y};
}

// The square root of how many classic fields a map holds, rounded: how many times it is as
// big each way, whatever its shape.
constexpr int mapScaleOf(int w, int h) {
    int scale = 1;
    while ((2 * scale + 1) * (2 * scale + 1) * kGridW * kGridH <= 4 * w * h) ++scale;
    return scale;
}

// Reference point of a cell: horizontal centre, bottom row.
constexpr int cellToPixelX(int cx) { return kOriginX + kCellW / 2 + cx * kCellW; }
constexpr int cellToPixelY(int cy) { return kOriginY + kCellH - 1 + cy * kCellH; }

// The two functions below keep the original's treatment of points left of /
// above the playfield (used only by bombs flying off the grid).
constexpr int pixelToCellX(int px) {
    int v = px < kOriginX ? px - kOriginX : px;
    return (v - kOriginX) / kCellW;
}
constexpr int pixelToCellY(int py) {
    const int half = kCellH / 2 - 1;
    int v = (py - kOriginY - half) < 0 ? py - (kOriginY - 1) : py;
    return (v - kOriginY - half) / kCellH;
}
constexpr Cell pixelToCell(int px, int py) { return {pixelToCellX(px), pixelToCellY(py)}; }

// Offset from the cell reference point: x in [-20, 19], y in [-18, 17].
constexpr int offsetInCellX(int px) {
    int v = px;
    while (v < kOriginX) v += kCellW;
    return (v - kOriginX) % kCellW - kCellW / 2;
}
constexpr int offsetInCellY(int py) {
    const int half = kCellH / 2 - 1;
    int v = py;
    while (v - kOriginY - half < 0) v += kCellH;
    return (v - kOriginY - half) % kCellH - (kCellH - 1) + half;
}

}  // namespace ab
