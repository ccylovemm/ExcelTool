// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     DropRandomDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _DROPRANDOMDATALOADER_H
#define _DROPRANDOMDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct DropRandomDataEntry
{
	DropRandomDataEntry() : calss(0), mir1(0), mir2(0), mir3(0), poweruprat(0), propaddrat(0), lucky(0){}
	virtual ~DropRandomDataEntry(){ }
	virtual UInt32 GetKey() const { return calss; }
	/**
	掉落类
	**/
	UInt16	calss;

	/**
	1卓越概率
	**/
	UInt16	mir1;

	/**
	2卓越概率
	**/
	UInt16	mir2;

	/**
	3卓越概率
	**/
	UInt16	mir3;

	/**
	强化概率
	**/
	UInt8	poweruprat;

	/**
	追加概率
	**/
	UInt8	propaddrat;

	/**
	出现幸运概率
	**/
	UInt8	lucky;
}; // DropRandomDataEntry define end

//data visitor for the excel table
template <typename T>
class DropRandomDataEntryVisitor
{
public:
	DropRandomDataEntryVisitor(){ static_assert(std::is_base_of<DropRandomDataEntry, T>::value != 0, "T must be inherited from DropRandomDataEntry"); }
	virtual ~DropRandomDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class DropRandomDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	DropRandomDataLoader(){ static_assert(std::is_base_of<DropRandomDataEntry, T>::value != 0, "T must be inherited from DropRandomDataEntry"); }
	~DropRandomDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "calss", pData->calss);
			doc.GetAttribute(pDataElem, "mir1", pData->mir1);
			doc.GetAttribute(pDataElem, "mir2", pData->mir2);
			doc.GetAttribute(pDataElem, "mir3", pData->mir3);
			doc.GetAttribute(pDataElem, "poweruprat", pData->poweruprat);
			doc.GetAttribute(pDataElem, "propaddrat", pData->propaddrat);
			doc.GetAttribute(pDataElem, "lucky", pData->lucky);
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

	void VisitData(DropRandomDataEntryVisitor<T>& visitor)
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

