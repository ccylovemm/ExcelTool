// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ActivityDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ACTIVITYDATALOADER_H
#define _ACTIVITYDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ActivityDataEntry
{
	ActivityDataEntry() : id(0), grade(0), reward1(0), num1(0), reward2(0), num2(0), reward3(0), num3(0){}
	virtual ~ActivityDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	序号
	**/
	UInt32	id;

	/**
	奖励阶
	**/
	UInt32	grade;

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

	/**
	奖励3
	**/
	UInt32	reward3;

	/**
	数量3
	**/
	UInt32	num3;
}; // ActivityDataEntry define end

//data visitor for the excel table
template <typename T>
class ActivityDataEntryVisitor
{
public:
	ActivityDataEntryVisitor(){ static_assert(std::is_base_of<ActivityDataEntry, T>::value != 0, "T must be inherited from ActivityDataEntry"); }
	virtual ~ActivityDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ActivityDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ActivityDataLoader(){ static_assert(std::is_base_of<ActivityDataEntry, T>::value != 0, "T must be inherited from ActivityDataEntry"); }
	~ActivityDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "grade", pData->grade);
			doc.GetAttribute(pDataElem, "reward1", pData->reward1);
			doc.GetAttribute(pDataElem, "num1", pData->num1);
			doc.GetAttribute(pDataElem, "reward2", pData->reward2);
			doc.GetAttribute(pDataElem, "num2", pData->num2);
			doc.GetAttribute(pDataElem, "reward3", pData->reward3);
			doc.GetAttribute(pDataElem, "num3", pData->num3);
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

	void VisitData(ActivityDataEntryVisitor<T>& visitor)
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

