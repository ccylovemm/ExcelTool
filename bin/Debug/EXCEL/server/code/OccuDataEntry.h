// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     OccuDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _OCCUDATALOADER_H
#define _OCCUDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct OccuDataEntry
{
	OccuDataEntry() : Job(0), JobStage(0){}
	virtual ~OccuDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	职业
	**/
	UInt8	Job;

	/**
	职业阶段
	**/
	UInt8	JobStage;

	/**
	职业名称
	**/
	string	Name;
}; // OccuDataEntry define end

//data visitor for the excel table
template <typename T>
class OccuDataEntryVisitor
{
public:
	OccuDataEntryVisitor(){ static_assert(std::is_base_of<OccuDataEntry, T>::value != 0, "T must be inherited from OccuDataEntry"); }
	virtual ~OccuDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class OccuDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	OccuDataLoader(){ static_assert(std::is_base_of<OccuDataEntry, T>::value != 0, "T must be inherited from OccuDataEntry"); }
	~OccuDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "Job", pData->Job);
			doc.GetAttribute(pDataElem, "JobStage", pData->JobStage);
			doc.GetAttribute(pDataElem, "Name", pData->Name);
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

	void VisitData(OccuDataEntryVisitor<T>& visitor)
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

