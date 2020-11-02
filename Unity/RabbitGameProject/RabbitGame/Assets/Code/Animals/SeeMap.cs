using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SeeMap
{
    public bool OnlySeeZone = true;

    World _world;
    int _seeRadius = 3;
    Transform _transform;
   
    public SeeMap(World world,Transform transform,int seeRadius)
    {
        _world = world;
        _transform = transform;
        _seeRadius = seeRadius;
    }

    public void UpdateSeeBlocks()
    {
        int x = _transform.position.X();
        int z = _transform.position.Z();

        if(OnlySeeZone) _world.DespawnWholeWorld();

        for (int w = x - _seeRadius; w <= x + _seeRadius; w++)
        {
            for(int h = z - _seeRadius; h <= z +_seeRadius; h++)
            {
                if(_world.HaveCoords(w,h))
                {
                    _world.SpawnBlock(w, h);

                }
            }
            
        }
    }

    
}
