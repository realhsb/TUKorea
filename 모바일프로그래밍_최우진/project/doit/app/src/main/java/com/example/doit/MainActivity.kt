package com.example.doit

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import androidx.recyclerview.widget.LinearLayoutManager
import com.example.doit.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding
    private lateinit var adapter: RecyclerViewAdapter

    var mDatas = mutableListOf<EventDTO>()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
//        setContentView(R.layout.activity_main)
        binding = ActivityMainBinding.inflate(layoutInflater)
        var view = binding.root
        setContentView(view)

        initEventRecyclerView()
        initializelist()
    }


    fun initEventRecyclerView(){
        val adapter=RecyclerViewAdapter() //어댑터 객체 만듦
        adapter.dataList=mDatas //데이터 넣어줌
        binding.recyclerView.adapter=adapter //리사이클러뷰에 어댑터 연결
        binding.recyclerView.layoutManager= LinearLayoutManager(this) //레이아웃 매니저 연결
    }

    fun initializelist(){ //임의로 데이터 넣어서 만들어봄
        with(mDatas){
            add(EventDTO("","dog1","2023-01-01","Soop"))
            add(EventDTO("","dog2","2023-01-01","Soop"))
            add(EventDTO("","dog3","2023-01-01","Soop"))
            add(EventDTO("","dog4","2023-01-01","Soop"))
            add(EventDTO("","dog5","2023-01-01","Soop"))
            add(EventDTO("","dog6","2023-01-01","Soop"))
            add(EventDTO("","dog7","2023-01-01","Soop"))
            add(EventDTO("","dog8","2023-01-01","Soop"))

        }
    }
}