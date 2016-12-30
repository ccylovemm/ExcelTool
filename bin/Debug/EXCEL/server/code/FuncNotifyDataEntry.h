// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     FuncNotifyDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _FUNCNOTIFYDATALOADER_H
#define _FUNCNOTIFYDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct FuncNotifyDataEntry
{
	FuncNotifyDataEntry() : id(0), beginTask(0), beginLevel(0), endTask(0), endLevel(0){}
	virtual ~FuncNotifyDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	功能id
	**/
	UInt16	id;

	/**
	触发任务ID
	**/
	UInt16	beginTask;

	/**
	触发等级
	**/
	UInt16	beginLevel;

	/**
	结束任务
	**/
	UInt16	endTask;

	/**
	结束等级
	**/
	UInt16	endLevel;
}; // FuncNotifyDataEntry define end

//data visitor for the excel table
template <typename T>
class FuncNotifyDataEntryVisitor
{
public:
	FuncNotifyDataEntryVisitor(){ static_assert(std::is_base_of<FuncNotifyDataEntry, T>::value != 0, "T must be inherited from FuncNotifyDataEntry"); }
	virtual ~FuncNotifyDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class FuncNotifyDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	FuncNotifyDataLoader(){ static_assert(std::is_base_of<FuncNotifyDataEntry, T>::value != 0, "T must be inherited from FuncNotifyDataEntry"); }
	~FuncNotifyDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "beginTask", pData->beginTask);
			doc.GetAttribute(pDataElem, "beginLevel", pData->beginLevel);
			doc.GetAttribute(pDataElem, "endTask", pData->endTask);
			doc.GetAttribute(pDataElem, "endLevel", pData->endLevel);
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

	void VisitData(FuncNotifyDataEntryVisitor<T>& visitor)
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

