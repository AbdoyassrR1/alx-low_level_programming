#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """ Returns the perimeter of an island described in grid """

    width = len(grid[0])
    height = len(grid)
    edge = 0
    size = 0

    for x in range(height):

        for y in range(width):

            if grid[x][y] == 1:
                size += 1
                if (y > 0 and grid[x][y - 1] == 1):
                    edge += 1
                if (x > 0 and grid[x - 1][y] == 1):
                    edge += 1

    return size * 4 - edge * 2
