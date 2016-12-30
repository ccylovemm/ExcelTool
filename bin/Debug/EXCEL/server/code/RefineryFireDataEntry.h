// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     RefineryFireDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _REFINERYFIREDATALOADER_H
#define _REFINERYFIREDATALOADER_H

#include <string>
#include <vector>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct RefineryFireDataEntry
{
	RefineryFireDataEntry() : id1(0), id2(0), fireid1(0), fireid2(0), fireid3(0), fireid4(0), fireid5(0){}
	virtual ~RefineryFireDataEntry(){ }
	virtual UInt32 GetKey() const { return 0xFFFFFFFF; };
	/**
	起火材料1
	**/
	UInt32	id1;

	/**
	起火材料2
	**/
	UInt32	id2;

	/**
	火焰1
	**/
	UInt32	fireid1;

	/**
	火焰2
	**/
	UInt32	fireid2;

	/**
	火焰3
	**/
	UInt32	fireid3;

	/**
	火焰4
	**/
	UInt32	fireid4;

	/**
	火焰5
	**/
	UInt32	fireid5;
}; // RefineryFireDataEntry define end

//data visitor for the excel table
template <typename T>
class RefineryFireDataEntryVisitor
{
public:
	RefineryFireDataEntryVisitor(){ static_assert(std::is_base_of<RefineryFireDataEntry, T>::value != 0, "T must be inherited from RefineryFireDataEntry"); }
	virtual ~RefineryFireDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class RefineryFireDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	RefineryFireDataLoader(){ static_assert(std::is_base_of<RefineryFireDataEntry, T>::value != 0, "T must be inherited from RefineryFireDataEntry"); }
	~RefineryFireDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "id1", pData->id1);
			doc.GetAttribute(pDataElem, "id2", pData->id2);
			doc.GetAttribute(pDataElem, "fireid1", pData->fireid1);
			doc.GetAttribute(pDataElem, "fireid2", pData->fireid2);
			doc.GetAttribute(pDataElem, "fireid3", pData->fireid3);
			doc.GetAttribute(pDataElem, "fireid4", pData->fireid4);
			doc.GetAttribute(pDataElem, "fireid5", pData->fireid5);
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

	void VisitData(RefineryFireDataEntryVisitor<T>& visitor)
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

