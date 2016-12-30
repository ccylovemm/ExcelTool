// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ChallengeRewardDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _CHALLENGEREWARDDATALOADER_H
#define _CHALLENGEREWARDDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ChallengeRewardDataEntry
{
	ChallengeRewardDataEntry() : id(0), rankMin(0), rankMax(0), rewardCredit(0), rewardToken(0){}
	virtual ~ChallengeRewardDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	id
	**/
	UInt32	id;

	/**
	名次最小范围
	**/
	UInt16	rankMin;

	/**
	名次最大范围
	**/
	UInt16	rankMax;

	/**
	奖励声望
	**/
	UInt32	rewardCredit;

	/**
	奖励伐仙令
	**/
	UInt32	rewardToken;
}; // ChallengeRewardDataEntry define end

//data visitor for the excel table
template <typename T>
class ChallengeRewardDataEntryVisitor
{
public:
	ChallengeRewardDataEntryVisitor(){ static_assert(std::is_base_of<ChallengeRewardDataEntry, T>::value != 0, "T must be inherited from ChallengeRewardDataEntry"); }
	virtual ~ChallengeRewardDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ChallengeRewardDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ChallengeRewardDataLoader(){ static_assert(std::is_base_of<ChallengeRewardDataEntry, T>::value != 0, "T must be inherited from ChallengeRewardDataEntry"); }
	~ChallengeRewardDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "rankMin", pData->rankMin);
			doc.GetAttribute(pDataElem, "rankMax", pData->rankMax);
			doc.GetAttribute(pDataElem, "rewardCredit", pData->rewardCredit);
			doc.GetAttribute(pDataElem, "rewardToken", pData->rewardToken);
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

	void VisitData(ChallengeRewardDataEntryVisitor<T>& visitor)
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

