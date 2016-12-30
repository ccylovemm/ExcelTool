// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ActiveEventDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ACTIVEEVENTDATALOADER_H
#define _ACTIVEEVENTDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ActiveEventDataEntry
{
	ActiveEventDataEntry() : id(0), times(0), activeDegree(0), retrieveSilver(0), retrieveGold(0), isRetrieve(0){}
	virtual ~ActiveEventDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	活跃度事件id
	**/
	UInt8	id;

	/**
	次数
	**/
	UInt8	times;

	/**
	完成一次活跃度
	**/
	UInt32	activeDegree;

	/**
	奖励
	**/
	string	reward;

	/**
	单次找回银币花费
	**/
	UInt32	retrieveSilver;

	/**
	单次找回元宝花费
	**/
	UInt32	retrieveGold;

	/**
	能否找回
	**/
	UInt8	isRetrieve;

	/**
	单次找回资源奖励
	**/
	string	retrieveReward;
}; // ActiveEventDataEntry define end

//data visitor for the excel table
template <typename T>
class ActiveEventDataEntryVisitor
{
public:
	ActiveEventDataEntryVisitor(){ static_assert(std::is_base_of<ActiveEventDataEntry, T>::value != 0, "T must be inherited from ActiveEventDataEntry"); }
	virtual ~ActiveEventDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ActiveEventDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ActiveEventDataLoader(){ static_assert(std::is_base_of<ActiveEventDataEntry, T>::value != 0, "T must be inherited from ActiveEventDataEntry"); }
	~ActiveEventDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "times", pData->times);
			doc.GetAttribute(pDataElem, "activeDegree", pData->activeDegree);
			doc.GetAttribute(pDataElem, "reward", pData->reward);
			doc.GetAttribute(pDataElem, "retrieveSilver", pData->retrieveSilver);
			doc.GetAttribute(pDataElem, "retrieveGold", pData->retrieveGold);
			doc.GetAttribute(pDataElem, "isRetrieve", pData->isRetrieve);
			doc.GetAttribute(pDataElem, "retrieveReward", pData->retrieveReward);
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

	void VisitData(ActiveEventDataEntryVisitor<T>& visitor)
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

