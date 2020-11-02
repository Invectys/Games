using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace RabbitGameServer.Models
{
    public class World
    {
        public int Width { get { return _width; } }
        public int Heigth { get { return _heigth; } }

        int _width, _heigth;
        EBlocks[,] _terrain;

        public World(int width, int heigth,EBlocks[,] terrain)
        {
            _width = width;
            _heigth = heigth;
            _terrain = terrain;
        }
    }
}

public enum EBlocks
{
    BGrass,
    BWater
}