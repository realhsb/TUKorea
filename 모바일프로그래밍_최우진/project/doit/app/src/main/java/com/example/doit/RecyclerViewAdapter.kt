package com.example.doit

import android.view.LayoutInflater
import android.view.ViewGroup
import androidx.recyclerview.widget.RecyclerView
import com.example.doit.databinding.ItemEventBinding

class RecyclerViewAdapter : RecyclerView.Adapter<RecyclerViewAdapter.MyViewHolder>() {

    var dataList = mutableListOf<EventDTO>()


    inner class MyViewHolder(private val binding: ItemEventBinding): RecyclerView.ViewHolder(binding.root) {
        //원래라면 class MyViewHolder(itemView:View):RecyclerView.Viewholder(itemView)인데 바인딩으로 구현!
        //binding전달받았기 때문에 홀더 내부 어디에서나 binding 사용가능
        fun bind(eventDTO:EventDTO){
//            binding.image=dogData.dog_img
            binding.txtEventName.text = eventDTO.eventTitle
            binding.txtDate.text = eventDTO.eventDate
            binding.txtOrganizer.text = eventDTO.eventOrganizer

        }
    }

    //만들어진 뷰홀더 없을때 뷰홀더(레이아웃) 생성하는 함수
    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyViewHolder {
        val binding=ItemEventBinding.inflate(LayoutInflater.from(parent.context),parent,false)
        return MyViewHolder(binding)
    }

    override fun getItemCount(): Int =dataList.size

    //recyclerview가 viewholder를 가져와 데이터 연결할때 호출
    //적절한 데이터를 가져와서 그 데이터를 사용하여 뷰홀더의 레이아웃 채움
    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {
        holder.bind(dataList[position])
    }

}