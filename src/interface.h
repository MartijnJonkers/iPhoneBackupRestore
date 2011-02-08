/*
 * interface.h
 *
 *  Created on: 4 jan. 2011
 *      Author: martijn
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <iostream>
#include <gtkmm.h>

class MainWindow  : public Gtk::Window{
public:
	MainWindow();
	~MainWindow();

private:
	void OnRowToggled(const Glib::ustring& path);
	bool FillTree();

	class ModelColumns : public Gtk::TreeModel::ColumnRecord{
	public:
		Gtk::TreeModelColumn<Glib::ustring> m_col_name;
		Gtk::TreeModelColumn<bool> m_col_active;
		ModelColumns(){
			add(m_col_active);
			add(m_col_name);
		}
	};

	ModelColumns m_Columns;
	Gtk::TreeModel::Row row;
	Gtk::ScrolledWindow m_ScrolledWindow;
	Gtk::TreeView m_TreeView;
	Glib::RefPtr<Gtk::TreeStore> m_refTreeModel;

	Gtk::VBox m_VBox;
};

#endif /* INTERFACE_H_ */
