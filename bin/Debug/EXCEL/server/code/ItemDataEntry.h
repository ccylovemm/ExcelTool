// ******************************************************************************************************/
// 这个是工具自动生成的表代码，这个里面的任何更改在下次生成之后会变得无效，请注意！<UTF-8 With BOM>
// 文件名：     ItemDataEntry.h
// Copyright(c) 2012-2100 上海恺英网络科技有限公司，All rights reserved.
// ******************************************************************************************************/


#ifndef _ITEMDATALOADER_H
#define _ITEMDATALOADER_H

#include <string>
#include <CLDefine.h>
#include <AvalonXmlDocument.h>
using namespace std;

//struct definition for the excel table
struct ItemDataEntry
{
	ItemDataEntry() : id(0), type(0), subtype(0), needlevel(0), itemlevel(0), color(0), bind(0), maxnum(0), demand(0), composition(0), decompose(0), product(0), suiteid(0), suitepos(0), sellprice(0), activetime(0), usetype(0), batch(0), cd(0), shellgroup(0), shellcd(0), p1(0), p2(0), p3(0), p4(0), p5(0), p6(0){}
	virtual ~ItemDataEntry(){ }
	virtual UInt32 GetKey() const { return id; }
	/**
	道具ID
	**/
	UInt32	id;

	/**
	道具名称
	**/
	string	name;

	/**
	道具图标
	**/
	string	icon;

	/**
	道具大类
	**/
	UInt16	type;

	/**
	道具小类
	**/
	UInt16	subtype;

	/**
	道具使用等级
	**/
	UInt16	needlevel;

	/**
	物品等级
	**/
	UInt16	itemlevel;

	/**
	道具品质（初始品质）
	**/
	UInt16	color;

	/**
	是否绑定
	**/
	UInt8	bind;

	/**
	最大可堆叠数量
	**/
	UInt16	maxnum;

	/**
	合成所需数量
	**/
	UInt8	demand;

	/**
	合成产物
	**/
	UInt32	composition;

	/**
	是否可分解
	**/
	UInt16	decompose;

	/**
	分解产物
	**/
	UInt16	product;

	/**
	道具描述
	**/
	string	description;

	/**
	描述辅助
	**/
	string	desc2;

	/**
	来源
	**/
	string	desc3;

	/**
	作用
	**/
	string	desc4;

	/**
	使用后触发的脚本ID
	**/
	string	script;

	/**
	套装ID
	**/
	UInt16	suiteid;

	/**
	套装位置
	**/
	UInt16	suitepos;

	/**
	出售价格
	**/
	UInt16	sellprice;

	/**
	有效时间
	**/
	UInt16	activetime;

	/**
	使用后是否消耗
	**/
	bool	usetype;

	/**
	是否批量使用
	**/
	UInt16	batch;

	/**
	冷却时间(秒)
	**/
	UInt16	cd;

	/**
	冷却组
	**/
	UInt16	shellgroup;

	/**
	组冷却时间
	**/
	UInt16	shellcd;

	/**
	参数1
	**/
	UInt16	p1;

	/**
	参数2
	**/
	UInt16	p2;

	/**
	参数3
	**/
	UInt16	p3;

	/**
	参数4
	**/
	UInt16	p4;

	/**
	参数5
	**/
	UInt16	p5;

	/**
	参数6
	**/
	UInt16	p6;

	/**
	道具掉落图标
	**/
	string	dropicon;

	/**
	道具掉落时的音效
	**/
	string	dropsound;

	/**
	装备外观
	**/
	string	battlemode;
}; // ItemDataEntry define end

//data visitor for the excel table
template <typename T>
class ItemDataEntryVisitor
{
public:
	ItemDataEntryVisitor(){ static_assert(std::is_base_of<ItemDataEntry, T>::value != 0, "T must be inherited from ItemDataEntry"); }
	virtual ~ItemDataEntryVisitor(){ }
	virtual bool operator()(T* pT){ return true; }
};

//data loader for the excel table
template <typename T>
class ItemDataLoader
{
public:
	HashMap<UInt32, T*> _mapData;

	ItemDataLoader(){ static_assert(std::is_base_of<ItemDataEntry, T>::value != 0, "T must be inherited from ItemDataEntry"); }
	~ItemDataLoader(){ ClearData(); }

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
			doc.GetAttribute(pDataElem, "icon", pData->icon);
			doc.GetAttribute(pDataElem, "type", pData->type);
			doc.GetAttribute(pDataElem, "subtype", pData->subtype);
			doc.GetAttribute(pDataElem, "needlevel", pData->needlevel);
			doc.GetAttribute(pDataElem, "itemlevel", pData->itemlevel);
			doc.GetAttribute(pDataElem, "color", pData->color);
			doc.GetAttribute(pDataElem, "bind", pData->bind);
			doc.GetAttribute(pDataElem, "maxnum", pData->maxnum);
			doc.GetAttribute(pDataElem, "demand", pData->demand);
			doc.GetAttribute(pDataElem, "composition", pData->composition);
			doc.GetAttribute(pDataElem, "decompose", pData->decompose);
			doc.GetAttribute(pDataElem, "product", pData->product);
			doc.GetAttribute(pDataElem, "description", pData->description);
			doc.GetAttribute(pDataElem, "desc2", pData->desc2);
			doc.GetAttribute(pDataElem, "desc3", pData->desc3);
			doc.GetAttribute(pDataElem, "desc4", pData->desc4);
			doc.GetAttribute(pDataElem, "script", pData->script);
			doc.GetAttribute(pDataElem, "suiteid", pData->suiteid);
			doc.GetAttribute(pDataElem, "suitepos", pData->suitepos);
			doc.GetAttribute(pDataElem, "sellprice", pData->sellprice);
			doc.GetAttribute(pDataElem, "activetime", pData->activetime);
			doc.GetAttribute(pDataElem, "usetype", pData->usetype);
			doc.GetAttribute(pDataElem, "batch", pData->batch);
			doc.GetAttribute(pDataElem, "cd", pData->cd);
			doc.GetAttribute(pDataElem, "shellgroup", pData->shellgroup);
			doc.GetAttribute(pDataElem, "shellcd", pData->shellcd);
			doc.GetAttribute(pDataElem, "p1", pData->p1);
			doc.GetAttribute(pDataElem, "p2", pData->p2);
			doc.GetAttribute(pDataElem, "p3", pData->p3);
			doc.GetAttribute(pDataElem, "p4", pData->p4);
			doc.GetAttribute(pDataElem, "p5", pData->p5);
			doc.GetAttribute(pDataElem, "p6", pData->p6);
			doc.GetAttribute(pDataElem, "dropicon", pData->dropicon);
			doc.GetAttribute(pDataElem, "dropsound", pData->dropsound);
			doc.GetAttribute(pDataElem, "battlemode", pData->battlemode);
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

	void VisitData(ItemDataEntryVisitor<T>& visitor)
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

