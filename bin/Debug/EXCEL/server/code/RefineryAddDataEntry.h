// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     RefineryAddDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _REFINERYADDDATALOADER_H
#define _REFINERYADDDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct RefineryAddDataEntry
{
	RefineryAddDataEntry() : id2(0), fireid2(0), fireid3(0), fireid4(0), fireid5(0){}
	virtual ~RefineryAddDataEntry(){ }
	virtual UInt32 GetKey() const { return id2; }
	/**
	物品颜色
	**/
	UInt32	id2;

	/**
	蓝火概率
	**/
	UInt32	fireid2;

	/**
	紫火概率
	**/
	UInt32	fireid3;

	/**
	金火概率
	**/
	UInt32	fireid4;

	/**
	红火概率
	**/
	UInt32	fireid5;
}; // RefineryAddDataEntry define end

//data visitor for the excel table
template <typename T>
class RefineryAddDataEntryVisitor
{
public:
	RefineryAddDataEntryVisitor(){ static_assert(std::is_base_of<RefineryAddDataEntry, T>::value != 0, "T must be inherited from RefineryAddDataEntry"); }
	virtual ~RefineryAddDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class RefineryAddDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	RefineryAddDataLoader(){ static_assert(std::is_base_of<RefineryAddDataEntry, T>::value != 0, "T must be inherited from RefineryAddDataEntry"); }
	~RefineryAddDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "id2", pData->id2);
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

	void VisitData(RefineryAddDataEntryVisitor<T>& visitor)
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

