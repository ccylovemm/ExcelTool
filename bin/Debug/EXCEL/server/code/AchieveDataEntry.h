// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     AchieveDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ACHIEVEDATALOADER_H
#define _ACHIEVEDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct AchieveDataEntry
{
	AchieveDataEntry() : id(0), limit(0), reward1(0), num1(0), reward2(0), num2(0){}
	virtual ~AchieveDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	序号
	**/
	UInt32	id;

	/**
	标题
	**/
	string	name;

	/**
	阶
	**/
	string	grade;

	/**
	描述
	**/
	string	describe;

	/**
	上限
	**/
	UInt32	limit;

	/**
	奖励1
	**/
	UInt32	reward1;

	/**
	数量1
	**/
	UInt32	num1;

	/**
	奖励2
	**/
	UInt32	reward2;

	/**
	数量2
	**/
	UInt32	num2;
}; // AchieveDataEntry define end

//data visitor for the excel table
template <typename T>
class AchieveDataEntryVisitor
{
public:
	AchieveDataEntryVisitor(){ static_assert(std::is_base_of<AchieveDataEntry, T>::value != 0, "T must be inherited from AchieveDataEntry"); }
	virtual ~AchieveDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class AchieveDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	AchieveDataLoader(){ static_assert(std::is_base_of<AchieveDataEntry, T>::value != 0, "T must be inherited from AchieveDataEntry"); }
	~AchieveDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "grade", pData->grade);
			doc.GetAttribute(pDataElem, "describe", pData->describe);
			doc.GetAttribute(pDataElem, "limit", pData->limit);
			doc.GetAttribute(pDataElem, "reward1", pData->reward1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
			doc.GetAttribute(pDataElem, "reward2", pData->reward2);
			doc.GetAttribute(pDataElem, "num2", pData->num2);
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

	void VisitData(AchieveDataEntryVisitor<T>& visitor)
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

