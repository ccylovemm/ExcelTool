// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     TaskChapterDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _TASKCHAPTERDATALOADER_H
#define _TASKCHAPTERDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct TaskChapterDataEntry
{
	TaskChapterDataEntry() : id(0), count(0), TaskIdBank(0){}
	virtual ~TaskChapterDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	号
	**/
	UInt16	id;

	/**
	回名称
	**/
	string	name;

	/**
	描述
	**/
	string	describe;

	/**
	任务总数
	**/
	UInt16	count;

	/**
	任务ID库
	**/
	UInt32	TaskIdBank;
}; // TaskChapterDataEntry define end

//data visitor for the excel table
template <typename T>
class TaskChapterDataEntryVisitor
{
public:
	TaskChapterDataEntryVisitor(){ static_assert(std::is_base_of<TaskChapterDataEntry, T>::value != 0, "T must be inherited from TaskChapterDataEntry"); }
	virtual ~TaskChapterDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class TaskChapterDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	TaskChapterDataLoader(){ static_assert(std::is_base_of<TaskChapterDataEntry, T>::value != 0, "T must be inherited from TaskChapterDataEntry"); }
	~TaskChapterDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "id", pData->id);
			doc.GetAttribute(pDataElem, "name", pData->name);
			doc.GetAttribute(pDataElem, "describe", pData->describe);
			doc.GetAttribute(pDataElem, "count", pData->count);
			doc.GetAttribute(pDataElem, "TaskIdBank", pData->TaskIdBank);
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

	void VisitData(TaskChapterDataEntryVisitor<T>& visitor)
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

