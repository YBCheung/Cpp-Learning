/************************人狗和谐关系管理办法（试行）************************/
//                                                                       
//*1.万物有名，名正言顺。新定义人/狗对象时，须在括号内指明姓名/编号。              
//*2.一人多狗，狗必忠贞。一人可以养不超过十只狗，一个狗可以指定一个主人。           
//*3.人有人格，狗有狗格。人可以添加删除狗，狗可以自由指定主人。人不可强夺有主之狗。
//                                                                       
//                                **ZYB帝国Cpp社区人狗关系管理办**    
//                                        **2019年1月7日**              
/**************************************************************************/


#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class CDog;
class CMan
{
	private:
		string mName;
		CDog *dog[10];
	public:
		CMan(const string &name);
		void DisplayName()
			{cout<<mName;}
		void DisplayDog();
		void AddDog(CDog &dog_new);   //为了使人狗关系同步，形参类要加&传递地址。
		void DelDog(CDog &dog_del);
		int beDelDog(CDog &dog_del);
};
class CDog
{
	private:
		string dName;
		CMan *host;
	public:
		CDog(const string &name)
			{dName=name;host=NULL;}
		void SetName(const string & name)
			{dName = name;}
		void DisplayName(void)
			{cout<<dName;}
		void DisplayHost(void)
			{if(host) host->DisplayName();else cout<<dName<<" has no host!\n";}
		void SetHost(CMan&man);       //狗选择主人时，调用人添加狗的函数
		friend class CMan;            //人添加狗时，直接通过友元修改狗的主人
};

/*************************CMan***************************/
CMan::CMan(const string &name)
{
	int i;
	mName=name;
	for(i=0;i<10;i++)
	{
		dog[i]=NULL;
	}
}
void CMan::AddDog(CDog &dog_new)
{
	int i=0;
	if(dog_new.host)
	{
		cout<<dog_new.host->mName<<" has already owned "<<dog_new.dName<<"!"<<endl;
		return;
	}
	while(dog[i])
	{
		i++;
		if(i>9)
		{
			cout<<this->mName<<" has owned enough dogs!"<<endl;
			return;
		}
	}
	dog[i]=&dog_new;
	dog[i]->host=this;
}

void CMan::DelDog(CDog &dog_del)
{
	int i;
	for(i=0;dog[i]&&i<10;i++)
	{
		if(dog[i]==&dog_del)     //找到目标狗
		{
			dog[i]->host=NULL;   //干掉目标狗主人
			while(dog[i+1]&&i<9) //删除目标狗，后方狗前移
			{
				dog[i]=dog[i+1];
				i++;
			}
			dog[i]=NULL;         //末尾狗清零收尾
			return;
		}
	}
	cout<<this->mName<<" did not own "<<dog_del.dName<<"!"<<endl;//没有找到目标狗
	return;
}
void CMan::DisplayDog()
{
	int i=0;
	cout<<mName<<" owns";
	while(dog[i]&&i<10)
	{
		cout<<endl<<i+1<<": ";
		dog[i]->DisplayName();
		i++;
	}
	if(i==0)
		cout<<" no dog!";
	cout<<endl;
}

/*************************CDog***************************/
void CDog::SetHost(CMan &man)
{
	if(host)
		host->DelDog(*this);
	man.AddDog(*this);
}

// 调用示例
// int main()
// {
// 	CMan zyb("zyb");
// 	CMan wmy("wmy");
// 	CDog Brutto("Brutto");
// 	CDog Goofy("Goofy");
// 	CDog Spike("Spike");
// 	CDog Spotty("Spotty");
// 	CDog Snoopy("Snoopy");
// 	CDog Droopy("Droopy");
// 	CDog Bolt("Bolt");
// 	CDog Hearty("Hearty");
// 	CDog Milou("Milou");
// 	CDog Koshiro("Koshiro");
// 	CDog BigbigWolf("BigbigWolf");
// 	zyb.AddDog(Brutto);
// 	zyb.AddDog(Goofy);
// 	zyb.AddDog(Spike);
// 	zyb.AddDog(Spotty);
// 	zyb.AddDog(Snoopy);
// 	zyb.AddDog(Droopy);
// 	zyb.AddDog(Bolt);
// 	zyb.AddDog(Hearty);
// 	zyb.AddDog(Milou);
// 	zyb.AddDog(Koshiro);
// 	zyb.AddDog(BigbigWolf);
// 	zyb.DisplayDog();
// 	Brutto.SetHost(wmy);
// 	zyb.AddDog(Brutto);
// 	zyb.DisplayDog();
// 	wmy.DisplayDog();
// 	return 0;
// }