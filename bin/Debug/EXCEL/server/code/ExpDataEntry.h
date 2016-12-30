// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ExpDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _EXPDATALOADER_H
#define _EXPDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ExpDataEntry
{
	ExpDataEntry() : level(0), exp(0), totalexp(0), sitbasicexp(0){}
	virtual ~ExpDataEntry(){ }
	virtual UInt32 GetKey() const { return level; }
	/**
	等级
	**/
	UInt16	level;

	/**
	升级经验
	**/
	UInt64	exp;

	/**
	累计经验
	**/
	UInt64	totalexp;

	/**
	打坐基础经验
	**/
	UInt16	sitbasicexp;
}; // ExpDataEntry define end

//data visitor for the excel table
template <typename T>
class ExpDataEntryVisitor
{
public:
	ExpDataEntryVisitor(){ static_assert(std::is_base_of<ExpDataEntry, T>::value != 0, "T must be inherited from ExpDataEntry"); }
	virtual ~ExpDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ExpDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ExpDataLoader(){ static_assert(std::is_base_of<ExpDataEntry, T>::value != 0, "T must be inherited from ExpDataEntry"); }
	~ExpDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "level", pData->level);
			doc.GetAttribute(pDataElem, "exp", pData->exp);
			doc.GetAttribute(pDataElem, "totalexp", pData->totalexp);
			doc.GetAttribute(pDataElem, "sitbasicexp", pData->sitbasicexp);
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

	void VisitData(ExpDataEntryVisitor<T>& visitor)
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

