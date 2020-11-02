using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Animal : MonoBehaviour
{


    public Movement Movement;
    public bool KeyBoardInputEnabled = true;
    public int SeeRadius = 3;

    Transform _transform;
    SeeMap _seeMap;

    


    void Awake()
    {
        Game game = Game.GetInstance();
        game.onWorldGenerated += WorldGenerated;
        Movement.StepEndEvent += onStepEnd;

        _transform = transform;
    }

    void Start()
    {
    }

    void Update()
    {
        if(KeyBoardInputEnabled)
        {
            MovementInput(KeyCode.W, new Vector3(0,0,1));
            MovementInput(KeyCode.S, new Vector3(0, 0, -1));
            MovementInput(KeyCode.A, new Vector3(-1, 0, 0));
            MovementInput(KeyCode.D, new Vector3(1, 0, 0));
        }
    }

    void MovementInput(KeyCode key, Vector3 dir)
    {
        if (Input.GetKey(key))
        {
            Movement.Step(dir);
        }

    }

    void WorldGenerated()
    {
        Game game = Game.GetInstance();
        _seeMap = new SeeMap(game.GetWorld(), _transform, SeeRadius);
        _seeMap.UpdateSeeBlocks();
    }

    void onStepEnd()
    {
        _seeMap.UpdateSeeBlocks();
    }
}
