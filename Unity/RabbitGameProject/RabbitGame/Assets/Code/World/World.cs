using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices.WindowsRuntime;
using UnityEngine;

public class World 
{

    public int Width { get { return _width; } }
    public int Heigth { get { return _heigth; } }

    int _width, _heigth;

    BlockInWorld[,] _terrain;
    BlockInWorld[,] _spawned;

    public World(int width,int heigth)
    {
        _width = width;
        _heigth = heigth;

        _terrain = new BlockInWorld[width, heigth];
        _spawned = new BlockInWorld[width, heigth];
    }

    public void SetBlock(int x, int z, BlockInWorld block)
    {
        _terrain[x,z] = block;
    }

    public BlockInWorld GetBlock(int x,int z)
    {
        return _terrain[x, z];
    }

    public bool HaveCoords(int x, int z)
    {
        bool valid1 = x >= 0 && x < _width;
        bool valid2 = z >= 0 && z < _heigth;
        return valid1 && valid2;
    }

    public void SpawnBlock(int x, int z)
    {
        BlockInWorld block = _terrain[x, z];

        var spawned = _spawned[x, z];
        if (spawned != null)
        {
            DespawnBlock(x, z);
        }

        _spawned[x, z] = GameObject.Instantiate(block, new Vector3(x, 0, z), new Quaternion());
    }

    public void DespawnBlock(int x,int z)
    {
        var obj = _spawned[x, z];
        if (obj != null)
        {
            GameObject.Destroy(obj.gameObject);
        }
    }

    public void SpawnWholeWorld()
    {
        for (int i = 0; i < _width; i++)
        {
            for (int i2 = 0; i2 < _heigth; i2++)
            {
                SpawnBlock(i, i2);
            }
        }
    }

    public void DespawnWholeWorld()
    {
        for (int i = 0; i < _width; i++)
        {
            for (int i2 = 0; i2 < _heigth; i2++)
            {
                DespawnBlock(i, i2);
            }
        }
    }

}


public static class WorldCalculations
{

    public static Vector3 FindSpawnLocation(World world,CanStayOn canStayOn)
    {
        int maxTry = 2000;
        int x, z;
        do
        {
            x = Random.Range(0, world.Width);
            z = Random.Range(0, world.Heigth);
            maxTry--;
        } while (!canStayOn.isPossibleStayOn(x, z) && maxTry > 0);

        return new Vector3(x, 1, z);
    }

}
