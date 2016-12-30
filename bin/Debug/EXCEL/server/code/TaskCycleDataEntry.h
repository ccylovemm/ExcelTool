// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TaskCycleDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TASKCYCLEDATALOADER_H
#define _TASKCYCLEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TaskCycleDataEntry
{
	TaskCycleDataEntry() : ID(0), name(0), MinLevel(0), MaxLevel(0), count(0), Type(0), activeEventId(0){}
	virtual ~TaskCycleDataEntry(){ }
	virtual UInt32 GetKey() const { return ID; }
	/**
	任务链ID
	**/
	UInt16	ID;

	/**
	名称
	**/
	UInt16	name;

	/**
	最小等级
	**/
	UInt16	MinLevel;

	/**
	最大等级
	**/
	UInt16	MaxLevel;

	/**
	任务环数
	**/
	UInt16	count;

	/**
	任务ID库
	**/
	string	TaskIdBank;

	/**
	10环额外奖励
	**/
	string	rewardsStr;

	/**
	任务类别
	**/
	UInt16	Type;

	/**
	计数键
	**/
	string	key;

	/**
	活跃度事件id
	**/
	UInt32	activeEventId;
}; // TaskCycleDataEntry define end

//data visitor for the excel table
template <typename T>
class TaskCycleDataEntryVisitor
{
public:
	TaskCycleDataEntryVisitor(){ static_assert(std::is_base_of<TaskCycleDataEntry, T>::value != 0, "T must be inherited from TaskCycleDataEntry"); }
	virtual ~TaskCycleDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TaskCycleDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TaskCycleDataLoader(){ static_assert(std::is_base_of<TaskCycleDataEntry, T>::value != 0, "T must be inherited from TaskCycleDataEntry"); }
	~TaskCycleDataLoader(){ ClearData(); }

	virtual bool ParseData(T* pT)
	{
		return true;
	}

	virtual bool AfterLoad()
	{
		return true;
	}

	bool LoadData(const std::string& strPath)
	{
		ClearData();
		Avalon::XmlDocument doc(strPath);
		if(!doc.LoadFile()) return false;
		Avalon::XmlElement* pElemRoot = doc.RootElement();
		if(pElemRoot == NULL)
		{
			return false;
		}
		TiXmlElement* pDataElem = doc.FirstChildElement(pElemRoot, "Row");
		UInt32 autoIncKey = 0;
		while(pDataElem != NULL)
		{
			T* pData = new T;
			doc.GetAttribute(pDataElem, "ID", pData->ID);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "MinLevel", pData->MinLevel);
			doc.GetAttribute(pDataElem, "MaxLevel", pData->MaxLevel);
			doc.GetAttribute(pDataElem, "count", pData->count);
			doc.GetAttribute(pDataElem, "TaskIdBank", pData->TaskIdBank);
			doc.GetAttribute(pDataElem, "rewardsStr", pData->rewardsStr);
			doc.GetAttribute(pDataElem, "Type", pData->Type);
			doc.GetAttribute(pDataElem, "key", pData->key);
			doc.GetAttribute(pDataElem, "activeEventId", pData->activeEventId);
			if(!ParseData(pData)) return false;
			if(pData->GetKey() != 0xFFFFFFFF)
			{
				if(!_mapData.insert(std::make_pair(pData->GetKey(), pData)).second)
				{
					delete pData;
					ClearData();
					return false;
				}
			}
			else
			{
				if(!_mapData.insert(std::make_pair(++autoIncKey, pData)).second)
					delete pData;
			}
			pDataElem = doc.NextElement(pDataElem);
		}
		return AfterLoad();
	}

	void VisitData(TaskCycleDataEntryVisitor<T>& visitor)
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end(); ++itr)
		{
			if(!visitor(itr->second))
				return;
		}
	}

	T* FindEntry(UInt32 key)
	{
		auto itr = _mapData.find(key);
		if(itr != _mapData.end())
			return itr->second;
		return NULL;
	}

	void ClearData()
	{
		for(auto itr = _mapData.begin(); itr != _mapData.end();++itr)
		{
			const T *p = itr->second;
			delete p;
		}
		_mapData.clear();
	}
};

#endif

