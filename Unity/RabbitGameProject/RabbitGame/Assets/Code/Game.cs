using System.Collections;
using System.Collections.Generic;
using UnityEditorInternal;
using UnityEngine;

public class Game 
{
    static Game _instance;
    public static Game GetInstance()
    {
        if(_instance == null)
        {
            _instance = new Game();
        }
        return _instance;
    }


    public delegate void GameEvent();
    public event GameEvent onWorldGenerated;
    public event GameEvent onGameStarted;

    Animal _playerAnimalPrefab;
    World _world;
    CameraMovement _playerCamera;

    public Game()
    {

    }

    public void SetWorld(World world)
    {
        _world = world;
        SpawnPlayer();
        if (onWorldGenerated != null) onWorldGenerated.Invoke();
    }
    public World GetWorld() => _world;

    public void SetCamera(CameraMovement playerCamera)
    {
        _playerCamera = playerCamera;
    }

    public CameraMovement GetPlayerCamera() => _playerCamera;

    public void SetPlayerAnimalPrefab(Animal animal)
    {
        _playerAnimalPrefab = animal;
    }
    public Animal GetPlayerAnimalPrefab() => _playerAnimalPrefab;


    public void StartGame()
    {
        if(onGameStarted != null) onGameStarted.Invoke();
    }

    void SpawnPlayer()
    {
        Vector3 spawnloc = WorldCalculations.FindSpawnLocation(Game.GetInstance().GetWorld(), GetPlayerAnimalPrefab().Movement.CanStayOn);
        Animal player = GameObject.Instantiate(GetPlayerAnimalPrefab(), spawnloc, new Quaternion());
        GetPlayerCamera().SpectateTo(player.transform);

    }
}

