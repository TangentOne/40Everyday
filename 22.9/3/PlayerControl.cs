using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControl : MonoBehaviour
{
    public float horizontalInput; //左右输入（左-右+)
    public float verticalInput; //前后输入（前+后-）
    public float[] xRange = { -15, 15 }; //x为左右方向
    public float[] zRange = { -6, 20 }; //z为前后方向
    public float speed = 10.0f;
    public GameObject projectilePrefab;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        horizontalInput = Input.GetAxis("Horizontal"); //获取左右输入
        verticalInput = Input.GetAxis("Vertical"); //获取前后输入

        transform.Translate(Vector3.right * horizontalInput * speed * Time.deltaTime);//左右移动
        transform.Translate(Vector3.forward * verticalInput * speed * Time.deltaTime);//前后移动

        //防止玩家出界
        if (transform.position.x < xRange[0])
            transform.position = new Vector3(xRange[0], transform.position.y, transform.position.z);
        if (transform.position.x > xRange[1])
            transform.position = new Vector3(xRange[1], transform.position.y, transform.position.z);
        if (transform.position.z < zRange[0])
            transform.position = new Vector3(transform.position.x, transform.position.y, zRange[0]);
        if (transform.position.z > zRange[1])
            transform.position = new Vector3(transform.position.x, transform.position.y, zRange[1]);

        //读取空格输入
        if(Input.GetKeyDown(KeyCode.Space))
        {
            Vector3 foodPosition = new Vector3(transform.position.x, transform.position.y + 2, transform.position.z);
            Quaternion foodRotation = projectilePrefab.transform.rotation;
            //实例化
            Instantiate(projectilePrefab, foodPosition, foodRotation);
        }
    }
}
