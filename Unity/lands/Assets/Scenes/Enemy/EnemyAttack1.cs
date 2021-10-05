using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyAttack1 : MonoBehaviour
{
    private Dictionary<Type, IEnemyBehaviour> _behaviorsMap;
    private IEnemyBehaviour _behaviorCorrent = null;

    private void initBehaviors()
    {
        _behaviorsMap = new Dictionary<Type, IEnemyBehaviour>();
        _behaviorsMap[typeof(EnemyBehaviourIdle)] = new EnemyBehaviourIdle();
        _behaviorsMap[typeof(EnemyBehaviourAggeassive)] = new EnemyBehaviourAggeassive();
        _behaviorsMap[typeof(EnemyBehaviourAimed)] = new EnemyBehaviourAimed();
    }


    private void setBehavior(IEnemyBehaviour newEnemyBehaviour)
    {
        if(_behaviorCorrent != null)
        {
            _behaviorCorrent.Exit();
        }
        _behaviorCorrent = newEnemyBehaviour;
        _behaviorCorrent.Enter();
    }


    private IEnemyBehaviour getBehavior<T>() where T: IEnemyBehaviour
    {
        var type = typeof(T);
        return _behaviorsMap[type];

    }

    private void setBehaviorByDefault()
    {
        setBehaviorIdle();
    }


    private void setBehaviorIdle()
    {
        var behavior = getBehavior<EnemyBehaviourIdle>();
        setBehavior(behavior);
    }


    private void setBehaviorAggeassive()
    {
        var behavior = getBehavior<EnemyBehaviourAggeassive>();
        setBehavior(behavior);
    }

    private void setBehaviorAimed()
    {
        var behavior = getBehavior<EnemyBehaviourAimed>();
        setBehavior(behavior);
    }


    [SerializeField] private Rigidbody2D _rbPlayer;

    private Rigidbody2D _rb;

    private Vector2 _playerPos;

    private Vector2 _enemyPos;

    private Vector2 _vector;

    private float _distance;
    private Vector2 _direction;


    [SerializeField] private float _enemuSpeed = 10f;
    [SerializeField] private float _aimedSpeed = 10f;

    [Tooltip("Видит ли враг тебя")]
    [SerializeField] bool _isVisible = false;

    [Tooltip("Прицелился ли враг")]
    [SerializeField] bool _isAimed = false;
    [Tooltip("Расстояние прицеливания")]
    [SerializeField] float _aimDistance = 2f;

    private void Start()
    {
        _rb = GetComponent<Rigidbody2D>();
        _playerPos = new Vector2();
        _enemyPos = new Vector2();
        initBehaviors();
        setBehaviorByDefault();
    }


    void Update()
    {
        
        //if (_isVisible && !_isAimed)
        if(_behaviorCorrent == _behaviorsMap[typeof(EnemyBehaviourAggeassive)])
        {
            _playerPos = new Vector2(_rbPlayer.transform.position.x, _rbPlayer.transform.position.y);
            _enemyPos = new Vector2(_rb.transform.position.x, _rb.transform.position.y);
            _vector = _playerPos - _enemyPos;

            _distance = _vector.magnitude;
            _direction = _vector / _distance;


            if (_distance > _aimDistance)
            {
                _rb.velocity = new Vector2(_direction.x * _enemuSpeed, _direction.y * _enemuSpeed);
            }
            else
            {
                //_isAimed = true;
                setBehaviorAimed();
            }
            
        }
        else if (_behaviorCorrent == _behaviorsMap[typeof(EnemyBehaviourAimed)])
        {
            _rb.velocity = new Vector2(_direction.x * _aimedSpeed, _direction.y * _aimedSpeed);
            _distance = _vector.magnitude;
            if (_distance > 20f)
            {
                _rb.velocity = new Vector2(0,0);
            }
        }
        else
        {
            _playerPos = new Vector2(_rbPlayer.transform.position.x, _rbPlayer.transform.position.y);
            _enemyPos = new Vector2(_rb.transform.position.x, _rb.transform.position.y);
            _vector = _playerPos - _enemyPos;

            _distance = _vector.magnitude;
            _direction = _vector / _distance;

            if (_distance < 10f)
            {
                //_isVisible = true;
                setBehaviorAggeassive();
            }
            else
            {
                //_isVisible = false;
                //_isAimed = false;
                setBehaviorIdle();
            }
        }
        if (_behaviorCorrent != null)
        {
            _behaviorCorrent.Update();
        }

    }


    private void OnCollisionEnter2D(Collision2D collision)
    {
        if(collision.gameObject.GetComponent<PlayerMove>() != null)
        {
            _isVisible = true;
            _isAimed = false;
            FindObjectOfType<GameManager>().EndGame();

        }
        else
        {
            _rb.velocity = new Vector2(0, 0);
            Destroy(gameObject, 2f);
        }
    }
}
