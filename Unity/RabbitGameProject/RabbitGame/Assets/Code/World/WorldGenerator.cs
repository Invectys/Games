using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using TMPro;
using UnityEngine;

public class WorldGenerator : MonoBehaviour
{

    [Header("Tests")]
    public bool SpawningWholeWorld = false;
    public bool LiveUpdateWorld = false;

    public SOTerrain TerrainSettings;
    public PerlinNoize TerrainPerlinNoize;

    public int mapWidth = 200;
    public int mapHeigth = 200;

    private World _world;

    

    void Start()
    {
        Debug.Log("Generating World...");
        _world = new World(mapWidth,mapHeigth);
        GenerateTerrain(_world);
        Game.GetInstance().SetWorld(_world);

        if (SpawningWholeWorld) _world.SpawnWholeWorld();
        if(LiveUpdateWorld)
        {
            StartCoroutine(LiveWorldUpdateCoroutine());
        }
    }

    void Update()
    {
        
    }

    IEnumerator LiveWorldUpdateCoroutine()
    {
        while(LiveUpdateWorld)
        {
           
            GenerateTerrain(_world);
            _world.SpawnWholeWorld();
            yield return new WaitForSecondsRealtime(1);
        }
    }

    World GenerateTerrain(World world)
    {
        Texture2D noizeMap = TerrainPerlinNoize.NoizeMap;
        int width = mapWidth;
        int heigth = mapHeigth;

        for(int x = 0; x < width; x++)
        {
            for(int z = 0; z < heigth; z++)
            {
                float val = noizeMap.GetPixel(x, z).r;
                var block = DetermineTerrainBlock(val);
                world.SetBlock(x, z, block);
            }
        }

        return world;
    }

    BlockInWorld DetermineTerrainBlock(float val)
    {
        foreach(var point in TerrainSettings.PerliBlocksRow)
        {
            if(val <= point.perlinPointValue)
            {
                return point.block;
            }
        }
        throw new Exception("There is no block that matches the value");
    }

}
