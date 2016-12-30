// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ChallengeTaskDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _CHALLENGETASKDATALOADER_H
#define _CHALLENGETASKDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ChallengeTaskDataEntry
{
	ChallengeTaskDataEntry() : id(0), spanMin(0), spanMax(0), rewardType(0), rewardID(0), rewardQuantity(0){}
	virtual ~ChallengeTaskDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	任务名
	**/
	string	taskName;

	/**
	天梯任务
	**/
	string	taskDescribe;

	/**
	取值最小范围
	**/
	UInt32	spanMin;

	/**
	取值最大范围
	**/
	UInt32	spanMax;

	/**
	奖励类型
	**/
	UInt32	rewardType;

	/**
	道具ID
	**/
	UInt32	rewardID;

	/**
	奖励值
	**/
	UInt32	rewardQuantity;
}; // ChallengeTaskDataEntry define end

//data visitor for the excel table
template <typename T>
class ChallengeTaskDataEntryVisitor
{
public:
	ChallengeTaskDataEntryVisitor(){ static_assert(std::is_base_of<ChallengeTaskDataEntry, T>::value != 0, "T must be inherited from ChallengeTaskDataEntry"); }
	virtual ~ChallengeTaskDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ChallengeTaskDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ChallengeTaskDataLoader(){ static_assert(std::is_base_of<ChallengeTaskDataEntry, T>::value != 0, "T must be inherited from ChallengeTaskDataEntry"); }
	~ChallengeTaskDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "taskName", pData->taskName);
			doc.GetAttribute(pDataElem, "taskDescribe", pData->taskDescribe);
			doc.GetAttribute(pDataElem, "spanMin", pData->spanMin);
			doc.GetAttribute(pDataElem, "spanMax", pData->spanMax);
			doc.GetAttribute(pDataElem, "rewardType", pData->rewardType);
			doc.GetAttribute(pDataElem, "rewardID", pData->rewardID);
			doc.GetAttribute(pDataElem, "rewardQuantity", pData->rewardQuantity);
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

	void VisitData(ChallengeTaskDataEntryVisitor<T>& visitor)
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

