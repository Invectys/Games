using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour
{
    public bool KeyBoardInputEnabled = false;
    public float MovementDelta = 2f;
    public float MoveToMaxDistanceDelta = 0.1f;
    public float SpectateDelta = 1f;
    public Vector3 SpectateOffset;
    float _defaultHeigth;
    Transform _transform;
    Transform _spectateTarget;

    public void MoveTo(Vector3 target)
    {
        StartCoroutine(MoveToCoroutine(target));
    }

    public void SpectateTo(Transform target)
    {
        _spectateTarget = target;
    }
    

    void Awake()
    {
        _transform = transform;
        _defaultHeigth = _transform.position.y;
    }

    void Start()
    {
        
    }

    void Update()
    {
        if(_spectateTarget != null)
        {
            Vector3 loc = Vector3.Lerp(_transform.position, _spectateTarget.position + SpectateOffset, SpectateDelta * Time.deltaTime);
            loc.y = _defaultHeigth;
            _transform.position = loc;
        }
        else if(KeyBoardInputEnabled)
        {
            KeyBoardInput(KeyCode.W, new Vector3(0, 0, MovementDelta));
            KeyBoardInput(KeyCode.S, new Vector3(0, 0, -MovementDelta));
            KeyBoardInput(KeyCode.A, new Vector3(-MovementDelta, 0, 0));
            KeyBoardInput(KeyCode.D, new Vector3(MovementDelta, 0, 0));

        }
    }

    
    void Zoom(float length)
    {
        Vector3 goal = _transform.forward * length;
    }



    void KeyBoardInput(KeyCode code,Vector3 delta)
    {
        if (Input.GetKey(code))
        {
            _transform.position += delta * Time.deltaTime;
        }
    }

    IEnumerator MoveToCoroutine(Vector3 target)
    {
        while(target != _transform.position)
        {
            _transform.position = Vector3.MoveTowards(_transform.position, target, MoveToMaxDistanceDelta);
            //_transform.position = Vector3.Lerp(_transform.position, target, MovementDelta);
            yield return null;
        }
        Debug.Log("Exit");
    }
}
